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