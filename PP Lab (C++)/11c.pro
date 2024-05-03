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

main :-
    write('Is John the grandparent of Sarah? '),
    (grandparent(john, sarah) -> write('Yes'), nl; write('No'), nl),
    write('Is Tom the grandparent of George? '),
    (grandparent(tom, george) -> write('Yes'), nl; write('No'), nl),
    write('Is Ann the grandparent of Sarah? '),
    (grandparent(ann, sarah) -> write('Yes'), nl; write('No'), nl).

:- initialization(main).

/*
Example query:
grandparent(john, sarah).
This query will return true because john is the grandparent of sarah.
*/
