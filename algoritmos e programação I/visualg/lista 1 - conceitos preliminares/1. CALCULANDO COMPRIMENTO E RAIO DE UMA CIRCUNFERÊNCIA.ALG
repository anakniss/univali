Algoritmo "Calculando comprimento e raio de uma circunfer�ncia"

//Fa�a  um  algoritmo  que  leia  o  raio  de  uma  circunfer�ncia  e  calcule  o
//  comprimento  e  a  �rea  da circunfer�ncia.

Var

area, comprimento, raio: real

Inicio

escreva("Digite o raio da circunfer�ncia: ")
leia(raio)

area <- pi * (raio ^ 2)
escreval("A �rea �: ", area:6:2)

comprimento <- 2 * pi * raio
escreval("O comprimento �: ", comprimento:6:2)

Fimalgoritmo