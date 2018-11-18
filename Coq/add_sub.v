Require Import Arith.

Definition f x := x + 100.
Definition g x := x - 100.

Theorem g_f : forall x, g (f x) = x.
Proof.
  intros x.
  unfold f, g.
  SearchRewrite(_ + _ - _).
  rewrite Nat.add_sub.
  reflexivity.
Qed.