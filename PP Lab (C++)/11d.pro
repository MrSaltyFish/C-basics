/*
 Anvesh Khode
 WAP in prolog to find a greater number
 among the 3 numbers. (using if-else)
*/

find_greatest(X, Y, Z, Greatest) :-
    (X >= Y, X >= Z ->
        Greatest = X
    ; Y >= X, Y >= Z ->
        Greatest = Y
    ;
        Greatest = Z
    ).

main :-
    write('Finding the greatest of 3, 7, and 5: '),
    find_greatest(3, 7, 5, Greatest1),
    write(Greatest1), nl,

    write('Finding the greatest of 9, 2, and 4: '),
    find_greatest(9, 2, 4, Greatest2),
    write(Greatest2), nl,

    write('Finding the greatest of 5, 5, and 5: '),
    find_greatest(5, 5, 5, Greatest3),
    write(Greatest3), nl,

    write('Finding the greatest of -3, -7, and -2: '),
    find_greatest(-3, -7, -2, Greatest4),
    write(Greatest4), nl.

:- initialization(main).
