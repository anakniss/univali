Algoritmo "Calculando o volume da lata de óleo"
// Disciplina: Algoritmo e Programação I
// Professor   : Fernanda
// Autor(a)    : Ana Clara Kniss
// Data atual  : 01/11/2022
Var

volume, raio, altura: real

Inicio

escreva("Informe o raio para calcular o volume: ")
leia(raio)

escreva("Informe a altura para calcular o volume: ")
leia(altura)

volume <- pi * (raio ^ 2) * altura
escreva("O volume da lata de óleo é: ", volume:6:2)

Fimalgoritmo