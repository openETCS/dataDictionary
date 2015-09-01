#!/bin/bash

# compute the times each solver would take for each of a given set of theories
provers="Alt-Ergo CVC4 Z3 Coq"
timeout=10
TIMEFORMAT=%R

theories_in() {
	sed -n 's/^.*theory \(.*\)$/\1/p' $1
}

# convert a time provided either in seconds or in milliseconds into a
# time in milliseconds
toms() {
	case $1 in
	*ms)
		echo ${1%ms} ;;
	*s)
		bc <<< "${1%s}*1000" | sed 's/\.[0-9]*$//' ;;
	*)
		# catch a variable left empty
		echo 0 ;;
	esac
}

# time_theory file theory prover
time_theory() {
	why3 prove $1 -L . -L $FRAMAC_SHARE/wp/why3/ -T $2 --prover $3 -t $timeout 2>/dev/null |
	tr -d '()' | (
		read _ _ _ _ valid time

		[[ "$valid" != "Valid" ]] && time=-1ms

		toms $time
		#echo $valid
	)
}

for file in *.why
do
	for theory in `theories_in $file`
	do
		printf %s,%s $file $theory
		for prover in $provers
		do
			printf ,%s `time_theory $file $theory $prover`
		done
		echo
	done
done

