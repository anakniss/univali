Algoritmo "Exercício 6 - Lista 2"

Var

opcao : inteiro
a, b, c: real

Inicio

   escreva("Digite sua opção: ")
   leia(opcao)
   escreva("Digite os valores a, b e c: ")
   leia(a)
   leia(b)
   leia(c)

   escolha (opcao)
     caso 1
       se (a < b) E (a < c) entao
         se(b < c) entao
           escreva(a, b, c)
         senao (b > c)
           escreva(a, c, b)
         fimse
       fimse
       se (b < a) E (b < c) entao
         se (a < c) entao
           escreva(b, a, c)
         senao (a > c)
           escreva(b, c, a)
         fimse
       fimse
       se (c < a) E (c < b) entao
         se (a < b) entao
           escreva(c, a, b)
         senao (a > b)
           escreva (c, b, a)
         fimse
       fimse
     caso 2
       se (a < b) E (a < c) entao
         se(b < c) entao
           escreva(c, b, a)
         senao (b > c)
           escreva(b, c, a)
         fimse
       fimse
       se (b < a) E (b < c) entao
         se (a < c) entao
           escreva(c, a, b)
         senao (a > c)
           escreva(a, c, b)
         fimse
       fimse
       se (c < a) E (c < b) entao
         se (a < b) entao
           escreva(b, a, c)
         senao (a > b)
           escreva (a, b, c)
         fimse
       fimse
     caso 3
       se (a < b) E (a < c) entao
         se(b < c) entao
           escreva(a, c, b)
         senao (b > c)
           escreva(a, b, c)
         fimse
       fimse
       se (b < a) E (b < c) entao
         se (a < c) entao
           escreva(b, c, a)
         senao (a > c)
           escreva(b, a, c)
         fimse
       fimse
       se (c < a) E (c < b) entao
         se (a < b) entao
           escreva(c, b, a)
         senao (a > b)
           escreva (c, a, b)
         fimse
       fimse
   fimescolha
Fimalgoritmo



