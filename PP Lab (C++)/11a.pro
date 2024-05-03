/*
Anvesh Khode
11a - WAP in prolog to perform +,-,/and * operations
of two numbers.
Take the number input from the user.
*/

add(X, Y):-
    Z is X + Y,
   write(Z), nl.

sub(X, Y):-
    Z is X - Y,
    write(Z), nl.

mult(X, Y):-
    Z is X * Y,
    write(Z), nl.

div(X, Y):-
    Z is X / Y,
    write(Z), nl.

rem(X, Y):-
    Z is X mod Y,
    write(Z), nl.

pow(X, Y):-
    Z is X**Y,
    write(Z), nl.

floord(X,Y):-
    Z is X // Y,
    write(Z), nl.

main :-
    write('Enter first number: '),
    read(X),
    write('Enter second number: '),
    read(Y),
    write('Choose operation (+, -, *, /): '),
    read(Operation),
    (Operation = '+' -> add(X, Y);
     Operation = '-' -> sub(X, Y);
     Operation = '*' -> mult(X, Y);
     Operation = '/' -> div(X, Y);
     write('Invalid operation'), nl).

% Start the program by initializing main predicate
:- initialization(main).
