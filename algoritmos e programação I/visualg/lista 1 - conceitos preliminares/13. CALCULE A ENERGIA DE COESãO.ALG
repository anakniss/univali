Algoritmo "13. Calcule a energia de coes�o"
// Tr�s  massas,  m1,  m2  e  m3,  est�o separadas por dist�ncias r12, r23 e r13
// (figura). Se G � a constante de gravita��o universal, a energia de coes�o
// mantendo a massa das part�culas juntas � dada pela f�rmula:
Var

massa1, massa2, massa3, massamedia1, massamedia2, massamedia3: real
metro1, metro2, metro3, energiaCoesao : real

Inicio

escreval("Informe a primeira massa em quilogramas: ")
leia(massa1)

escreval("Informe a primeira dist�ncia em metros: ")
leia(metro1)

escreval("Informe a segunda massa em quilogramas: ")
leia(massa2)

escreval("Informe a segunda dist�ncia em metros: ")
leia(metro2)

escreval("Informe a terceira massa em quilogramas: ")
leia(massa3)

escreval("Informe a terceira dist�ncia em metros: ")
leia(metro3)

massamedia1 <- (massa1 * massa2)
massamedia2 <- (massa1 * massa3)
massamedia3 <- (massa2 * massa3)

energiaCoesao <- (6.67 * (10 ^ -11)) *((massamedia1 / metro1) + (massamedia2 / metro2) + (massamedia3 / metro3))

escreval("A energia de coes�o �: ", energiaCoesao)
Fimalgoritmo