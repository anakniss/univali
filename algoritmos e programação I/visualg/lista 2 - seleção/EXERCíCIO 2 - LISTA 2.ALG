Algoritmo "Exercício 2 - Lista 2"

Var

a, b, c, max: inteiro

Inicio

leia(a, b, c)
   se a > b entao
      se a > c entao
        max <- a
      senao
        max <- c
      fimse
   senao
      se b > c entao
        max <- b
      senao
        max <- c
      fimse
   fimse
   escreva("Maior entre ", a, ",", b, " e", c, ":", max)
   
FimAlgoritmo