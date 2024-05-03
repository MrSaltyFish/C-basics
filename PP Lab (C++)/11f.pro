/*
Anvesh Khode
11f - WAP in prolog to find cubes of a given number
*/

cube(X, Result) :-
    Result is X * X * X.

main :-
    write('Cube of 3: '),
    cube(3, Result1),
    write(Result1), nl,

    write('Cube of 5: '),
    cube(5, Result2),
    write(Result2), nl,

    write('Cube of -2: '),
    cube(-2, Result3),
    write(Result3), nl,

    write('Cube of 0: '),
    cube(0, Result4),
    write(Result4), nl.

:- initialization(main).
