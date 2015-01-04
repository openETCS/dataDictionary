
Require Import ZArith.
Require Import Qedlib.
Require Import Memory.
Require Import Cint.
Require Import BuiltIn.
Require Import Cbits.

Open Local Scope Z_scope.

Lemma Cdiv_bounds :
     (forall n d x,
       n >= 0 ->
       d > 0 ->
       n < x * d ->
       0 <= (Cdiv n d) < x)%Z.
Proof.
  intros.
  assert(X: Cdiv n d = n/d).
    apply Cdiv_cases; omega.
  rewrite X.

  split.
  + apply Z_div_pos; omega.
  + apply Zdiv_lt_upper_bound; omega.
Qed.

Lemma bitwise_and_not_uint8:
  forall (a b : Z),
  (is_uint8 a%Z) ->
  (is_uint8 b%Z) ->
  (0 <= (land a (lnot b)) <= 255)%Z.
Proof.
  admit.
Qed.


Lemma bits_equal_uint64 :
   (forall x y,
      is_uint64 x ->
      is_uint64 y ->
      (forall i: int, (0 <= i)%Z -> (i <= 63)%Z -> (bit_test x i <-> bit_test y i)) ->
      x = y).
Proof.
  intros.
  admit.
Qed.


Lemma upper_bits_not_set :
  (forall x n,
        0 <= x ->
        0 <= n ->
        ( (x < lsl 1 n) <-> 
        (forall k: int, n <= k -> ~(bit_test x k))))%Z.
Proof.
  intros.
  split.
  +  intros.
     admit. (* is_uint64_lsl1_sup *)
  +  intros.
     admit.
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


Lemma shift_different :
   (forall a i j, i <> j -> (shift a i) <> (shift a j))%Z.
Proof.
   intros.
   intuition.
   assert(offset (shift a i) = offset (shift a j)).
     rewrite H0.
     reflexivity.
   simpl in H1.
   auto with zarith.
Qed.
