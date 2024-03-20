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

/*
Example queries:
factorial(5, X).
This query will find the factorial of 5 and bind the result to X.

factorial(0, X).
This query will find the factorial of 0 and bind the result to X.
*/