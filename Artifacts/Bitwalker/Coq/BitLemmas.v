
Require Import ZArith.
Require Import Memory.
Require Import Cint.
Require Import BuiltIn.

Open Local Scope Z_scope.

Lemma bits_and_bounds :
  forall x n,
        0 <= x ->
        0 <= n ->
        ( (x < lsl 1 n)%Z <-> 
        (forall k: int, (n <= k)%Z -> (k <= 63)%Z -> ~(bit_test x k))).
Proof.
  intros.
  split; admit.
Qed.

Lemma shift_zero :
   forall a, (shift a 0) = a.
Proof.
  intros a. 
  unfold shift.
  replace (offset a + 0) with (offset a) by auto with zarith.
  induction a.
  simpl.
  trivial.
Qed.

Lemma shift_injective :
   forall a, forall i j, (shift a i) = (shift a j) -> i = j.
Proof.
  intros a i j EQ.
  assert(offset (shift a i) = offset (shift a j)).
  rewrite EQ. trivial.
  unfold shift in H.
  simpl in H.
  auto with zarith.
Qed.

