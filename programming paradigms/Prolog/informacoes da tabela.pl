% pessoa(nome, sexo, idade, altura, peso)

pessoa('Ana', fem, 23, 1.55, 56.0).
pessoa('Bia', fem, 19, 1.71, 61.3).
pessoa('Ivo', masc, 22, 1.80, 70.9).
pessoa('Lia', fem, 17, 1.85, 57.3).
pessoa('Eva', fem, 28, 1.75, 68.7).
pessoa('Ary', masc, 25, 1.72, 68.9).

% a) Quais são as mulheres com mais de 20 anos de idade?

mais20(N) :- pessoa(N, fem, I, _, _), I >= 20.

% b) Quem tem pelo menos 1.70m de altura e menos de 65kg?

quem(N) :- pessoa(N, _, _, A, P), A =< 1.70, P < 65.

% c) Quais são os possíveis casais onde o homem é mais alto que a mulher?

casal(N, N1) :- pessoa(N, fem, _, A, _), pessoa(N1, masc, _, A1, _), A < A1.

% O peso ideal para uma modelo é no máximo 62.1*Altura–44.7 . Além
% disso, para ser modelo, uma mulher precisa ter mais que 1.70m de altura e menos de 25 anos de idade.
% Com base nessas informações, e considerando a tabela do exercício anterior, defina um predicado 
% capaz de recuperar apenas os nomes das mulheres que podem ser modelos.

modelo(N) :- pessoa(N, fem, I, A, P), I =< 25, A >= 1.70, PM is 62.1 * A - 44.7, P =< PM.