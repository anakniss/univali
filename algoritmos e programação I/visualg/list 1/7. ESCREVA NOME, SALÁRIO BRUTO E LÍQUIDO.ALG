Algoritmo "7. ESCREVA NOME, SALÁRIO BRUTO E LÍQUIDO"
// Uma  empresa  tem  para  um  funcionário  os  seguintes  dados:  o  nome  do
// funcionário,  o  número  de  horas trabalhadas mensais e o número de
// dependentes. A empresa paga R$ 10,00 por hora (valor para cálculo do salário
// trabalho) e R$ 60,00 por dependente (valor para cálculo do salário família)
// e são feitos descontos de 8,5% sobre o salário trabalho para o INSS e de 5%
// sobre o salário trabalho para o imposto de renda. Faça um algoritmo que
// escreva o nome, o salário bruto e o salário líquido do funcionário.

Var
nome : caracter
horasTrabalhadas, salarioBruto, salarioLiquido, valorDependentes : real
numeroDependentes : inteiro

Inicio
escreval("Informe seu nome: ")
leia(nome)

escreval("Informe a quantidade de horas trabalhadas: ")
leia(horasTrabalhadas)

escreval("Informe a quantidade de dependentes que você possui: ")
leia(numeroDependentes)

salarioBruto <- 10 * horasTrabalhadas + (numeroDependentes * 60)

salarioLiquido <- salarioBruto - ((salarioBruto * 0.085) + (salarioBruto * 0.05))

escreval("Nome: ", nome)
escreval("Salário Bruto: ", salarioBruto)
escreval("Salário Líquido: ", salarioLiquido)

Fimalgoritmo