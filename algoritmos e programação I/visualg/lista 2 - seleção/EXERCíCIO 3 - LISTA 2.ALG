Algoritmo "Exercício 3 - Lista 2"

Var

a, p1, b, p2, c, p3, mediaPonderada: real

Inicio

leia(a, b, c)

se(a > b) e (a > c) entao
  p1 <- 5
  p2 <- 2.5
  p3 <- 2.5
fimse

se (b > a) e (b > c) entao
  p2 <- 5
  p1 <- 2.5
  p3 <- 2.5
fimse

se (c > a) e (c > b) entao
  p3 <- 5
  p1 <- 2.5
  p2 <- 2.5
fimse

mediaPonderada <- ((a * p1) + (b * p2) + (c * p3)) / (p1 + p2 + p3)

escreva("A média ponderada é: ", mediaPonderada)

FimAlgoritmo