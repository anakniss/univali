Algoritmo "14. Maior valor entre dois n�meros"
// Fa�a um algoritmo que leia 2 valores a, b e escreva o maior deles usando
// a f�rmula abaixo:
Var
varA, varB, abso,  maior: real


Inicio
escreval("Digite o primeiro valor: ")
leia(varA)

escreval("Digite o segundo valor: ")
leia(varB)


abso <- abs(varA - varB)

maior <- (varA + varB + abso) / 2

escreval("O valor maior entre ambos valores �: ", maior)

Fimalgoritmo