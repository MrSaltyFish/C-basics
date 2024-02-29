/*
Anvesh Khode
11b - WAP in prolog to create a family tree
*/

female(pam).
female(liza).
female(pat).
female(ann).
male(bob).
male(tom).
male(peter).
male(jim).
parent(pam,bob).
parent(tom,bob).
parent(tom,liza).
parent(bob,ann).
parent(pat,jim).
parent(bob,peter).
mother(X,Y):-parent(X,Y),female(X).
father(X,Y):-parent(X,Y),male(x).
