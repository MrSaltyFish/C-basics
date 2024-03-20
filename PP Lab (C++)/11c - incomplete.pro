/*
Anvesh Khode
11c - WAP in prolog X is the grandparent of Y or not
*/

parent(john, tom).
parent(john, mary).
parent(tom, ann).
parent(tom, peter).
parent(ann, george).
parent(peter, sarah).

grandparent(X, Y) :-
    parent(X, Z),
    parent(Z, Y).

/*
Example query:
grandparent(john, sarah).
This query will return true because john is the grandparent of sarah.
*/
