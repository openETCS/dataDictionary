#!/bin/bash

# run solvers with exponentially rising timeout on a given set of
# why-files to speed up the verification process by avoiding long
# timeouts.

usage() {
	echo Usage: $0 [ -t maxtimeout ] files...
	exit 1
}

# verify a single theory. Output:
# * if succesful to fd 3,
# * if timeout to fd 1
# * if $5 true to fd 2
# * if $5 is false to fd 1
single_theory() {
	local output=`why3 prove $1 -L . -L $FRAMAC_SHARE/wp/why3/ -T $2 --prover $3 -t $4 2>/dev/null`

	case "$output" in
	*Valid*)
		echo $1,$2 >&3 ;;
	*Timeout*)
		echo $1,$2 >&1 ;;
	'')
		# ignore when nothing has been proven
		;;
	*)
		# everything else is a failure
		if $5
		then
			echo FAILED\  $2 from $1 "($output)" >&2
		else
			echo $1,$2 >&1
		fi
		;;
	esac
}

do_theories() {
	while IFS=',' read file theory
	do
		single_theory $file $theory $1 $2 $3
	done
}

enumerate_theories() {
	for file in "$@"
	do
		for theory in `sed -n 's/^.*theory \(.*\)$/\1/p' $file`
		do
			echo $file,$theory
		done
	done
}

single_pass() {
	local timeout=$1
	local theories=/dev/fd/0

	for prover in $provers
	do
		printf "Verifying %s theories with %s, timeout is %s... " $thcount $prover $timeout >&2
		local remaining=`mktemp remaining.XXXXXXX`

		if [ "$prover" = "${provers/* }" ]
		then
			islastprover=true
		else
			islastprover=false
		fi

		do_theories $prover $timeout $islastprover <$theories 2>&1 >$remaining 3>/dev/null

		[ "$theories" != /dev/fd/0 ] && rm -f $theories
		theories=$remaining
		local thcount=`wc -l <$theories`
		echo $thcount theories remain >&2

		[ "$thcount" = 0 ] && break
	done

	cat $theories
	rm -f $theories
}

show_timeouts() {
	while IFS=, read file theory
	do
		echo TIMEOUT $theory from $file
	done
}

maxtimeout=32

while getopts "t:" option
do
	case "$option" in
	t)
		maxtimeout=$OPTARG ;;
	*)
		usage ;;
	esac
done

shift $((OPTIND-1))

[ -z "$*" ] && usage

provers="Alt-Ergo Z3 CVC4"
theories=`mktemp theories.XXXXXX`
enumerate_theories "$@" >$theories
thcount=`wc -l <$theories`
echo Found $thcount theories >&2

timeout=1
while [ $timeout -le $maxtimeout ]
do
	echo Using a timeout of $timeout seconds >&2
	remaining=`mktemp remaining.XXXXXX`
	single_pass $timeout <$theories >$remaining

	rm -f $theories
	theories=$remaining
	thcount=`wc -l <$theories`
	[ "$thcount" = 0 ] && break
	timeout=$((timeout*2))
done

if [ "$thcount" != 0 ]
then
	echo $thcount theories could not be verified with this timeout >&2
	show_timeouts <$theories
fi

rm $theories
