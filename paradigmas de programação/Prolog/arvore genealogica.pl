mae(ana, eva).
mae(bia, rai).
mae(bia, clo).
mae(bia, ary).
mae(eva, noe).
mae(lia, gal).
pai(gil, rai).
pai(gil, clo).
pai(gil, ary).
pai(ivo, eva).
pai(rai, noe).
pai(ary, gal).

homem(ivo).
homem(gil).
homem(rai).
homem(ary).
homem(noe).

mulher(ana).
mulher(bia).
mulher(eva).
mulher(clo).
mulher(lia).
mulher(gal).

gerou(ana, eva).
gerou(ivo, eva).
gerou(bia, rai).
gerou(bia, clo).
gerou(bia, ary).
gerou(gil, rai).
gerou(gil, clo).
gerou(gil, ary).
gerou(eva, noe).
gerou(rai, noe).
gerou(ary, gal).
gerou(lia, gal).

filho(F, P) :- homem(F), gerou(P, F).
filha(F, P) :- mulher(F), gerou(P, F).
tio(T, S) :- homem(T), gerou(V, T), gerou(V, I), gerou(I, S), T \== I.
tia(T, S) :- mulher(T), gerou(V, T), gerou(V, I), gerou(I, S), T \== I.
primo(P1, P2) :- homem(P1), gerou(V, T1), gerou(V, T2), gerou(T1, P1), gerou(T2, P2), P1 \== P2, T1 \== T2.
prima(P1, P2) :- mulher(P1), gerou(V, T1), gerou(V, T2), gerou(T1, P1), gerou(T2, P2), P1 \== P2, T1 \== T2.
avô(V, N) :- homem(V), pai(V, P), filho(N, P).
avô(V, N) :- homem(V), pai(V, M), filha(N, M).
avó(V, N) :- mulher(V), mae(V, P), filho(N, P).
avó(V, N) :- mulher(V), mae(V, M), filha(N, M).


