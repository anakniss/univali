Algoritmo "Exerc�cio 1 - Lista 2"

Var

numero: inteiro
sexo: caracter

Inicio

leia(numero)

se(numero >= 20) e (numero <= 90) entao
  escreva("N�mero no intervalo [20, 90]")
senao
  escreval("N�mero fora do intervalo [20,90]")
fimse

leia(sexo)

se(sexo="m") ou (sexo = "f") entao
  escreva("Dado v�lido")
senao
  escreval("Dado incorreto")
fimse

FimAlgoritmo