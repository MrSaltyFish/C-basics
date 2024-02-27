/*
Anvesh Khode
11a - WAP in prolog to perform operations
of two numbers take the nos input from the user.
*/

add(X, Y):-
    Z is X + Y,
   write(Z).

sub(X, Y):-
    Z is X - Y,
    write(Z).

mult(X, Y):-
    Z is X * Y,
    write(Z).

div(X, Y):-
    Z is X / Y,
    write(Z).

rem(X, Y):-
    Z is X mod Y,
    write(Z).

pow(X, Y):-
    Z is X**Y,
    write(Z).
floord(X,Y):-
Z is X // Y,
write(Z).
