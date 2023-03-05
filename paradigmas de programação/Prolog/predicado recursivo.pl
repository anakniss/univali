produto(0, _, 0).
produto(N, N2, R) :-
    N>0,
    M is N-1,
    produto(M, N2, R1),
    R is R1 + N2.