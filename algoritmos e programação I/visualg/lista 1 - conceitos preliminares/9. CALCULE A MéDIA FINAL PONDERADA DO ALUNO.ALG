Algoritmo "9. Calcule a m�dia final ponderada do aluno"
// Fa�a um algoritmo que leia o nome de um aluno, as tr�s notas obtidas no
// decorrer do semestre (n1, n2, n3) e os respectivos pesos (p1, p2, p3).
// Escreva o nome e a m�dia final ponderada do aluno.
Var
nome : caracter
nota1, nota2, nota3, mediaPonderada : real
peso1, peso2, peso3 : inteiro

Inicio
escreval("Digite seu nome: ")
leia(nome)

escreval("Digite a primeira nota que voc� obteve: ")
leia(nota1)

escreval("Informe o peso desta nota: ")
leia(peso1)

escreval("Digite a segunda nota que voc� obteve: ")
leia(nota2)

escreval("Informe o peso desta nota: ")
leia(peso2)

escreval("Digite a terceira nota que voc� obteve: ")
leia(nota3)

escreval("Informe o peso desta nota: ")
leia(peso3)

mediaPonderada <- ((nota1 * peso1) + (nota2 * peso2) + (nota3 * peso3)) / (peso1 + peso2 + peso3)

escreval("A m�dia final ponderada �: ", mediaPonderada)

Fimalgoritmo