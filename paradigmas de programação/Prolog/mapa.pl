% estrada(Origem, Destino, Km)

estrada(a, b, 25).
estrada(a, d, 23).
estrada(b, c, 19).
estrada(b, e, 32).
estrada(c, d, 14).
estrada(c, f, 28).
estrada(d, f, 30).
estrada(e, f, 26).

dist(A, B, D) :- estrada(A, B, DV), D is DV.
dist(A, B, D) :- estrada(A, V, DV), dist(V, B, DVB), D is DV + DVB.