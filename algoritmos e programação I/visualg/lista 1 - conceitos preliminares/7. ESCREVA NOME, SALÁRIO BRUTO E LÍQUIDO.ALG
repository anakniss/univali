Algoritmo "7. ESCREVA NOME, SAL�RIO BRUTO E L�QUIDO"
// Uma  empresa  tem  para  um  funcion�rio  os  seguintes  dados:  o  nome  do
// funcion�rio,  o  n�mero  de  horas trabalhadas mensais e o n�mero de
// dependentes. A empresa paga R$ 10,00 por hora (valor para c�lculo do sal�rio
// trabalho) e R$ 60,00 por dependente (valor para c�lculo do sal�rio fam�lia)
// e s�o feitos descontos de 8,5% sobre o sal�rio trabalho para o INSS e de 5%
// sobre o sal�rio trabalho para o imposto de renda. Fa�a um algoritmo que
// escreva o nome, o sal�rio bruto e o sal�rio l�quido do funcion�rio.

Var
nome : caracter
horasTrabalhadas, salarioBruto, salarioLiquido, valorDependentes : real
numeroDependentes : inteiro

Inicio
escreval("Informe seu nome: ")
leia(nome)

escreval("Informe a quantidade de horas trabalhadas: ")
leia(horasTrabalhadas)

escreval("Informe a quantidade de dependentes que voc� possui: ")
leia(numeroDependentes)

salarioBruto <- 10 * horasTrabalhadas + (numeroDependentes * 60)

salarioLiquido <- salarioBruto - ((salarioBruto * 0.085) + (salarioBruto * 0.05))

escreval("Nome: ", nome)
escreval("Sal�rio Bruto: ", salarioBruto)
escreval("Sal�rio L�quido: ", salarioLiquido)

Fimalgoritmo