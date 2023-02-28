Algoritmo "12. Calcule x e y de um sistema linear"
//Texto com muitas formatações

Var
varA, varB, varC, varD, varE, varF, varX, varY : real

Inicio
escreval("Informe o valor A: ")
leia(varA)

escreval("Informe o valor B: ")
leia(varB)

escreval("Informe o valor C: ")
leia(varC)

escreval("Informe o valor D: ")
leia(varD)

escreval("Informe o valor F: ")
leia(varF)

varX <- ((varC * varE) - (varB * varF)) / ((varA * varE) - (varB * varD))

escreval("O valor de X é: ", varX)

varY <- ((varF * varF) - (varC * varD)) / ((varA * varE) - (varB * varD))

escreval("O valor de Y é: ", varY)

Fimalgoritmo