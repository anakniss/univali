Algoritmo "11. Calcule a temperatura de Fahrenheit para Celsius"
// Faça um algoritmo que leia uma temperatura em °F e escreva o seu valor em
// °F e seu valor em °C da seguinte forma:
// Fahrenheit = Valor lido
// Celsius = Valor calculado
Var
fahrenheit, celsius : real

Inicio

escreval("Informe os graus em Fahrenheit: ")
leia(fahrenheit)

celsius <- (fahrenheit - 32)  / (9/5)

escreval("O valor em Celsius é: ", celsius)

Fimalgoritmo