/*
Anvesh Khode
11e- WAP in prolog to find factorial of number.
*/

factorial(0, 1).
factorial(N, Result) :-
    N > 0,
    N1 is N - 1,
    factorial(N1, SubFactorial),
    Result is N * SubFactorial.

main :-
    write('Factorial of 5: '),
    factorial(5, Result1),
    write(Result1), nl,

    write('Factorial of 0: '),
    factorial(0, Result2),
    write(Result2), nl,

    write('Factorial of 7: '),
    factorial(7, Result3),
    write(Result3), nl,

    write('Factorial of 3: '),
    factorial(3, Result4),
    write(Result4), nl.

:- initialization(main).

/*
Example queries:
factorial(5, X).
This query will find the factorial of 5 and bind the result to X.

factorial(0, X).
This query will find the factorial of 0 and bind the result to X.
*/