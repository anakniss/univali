Algoritmo "10. Calcule o salário líquido do funcionário com descontos"
// Considere  que  o  salário  líquido  de  um  funcionário  é  calculado
// através  de  um  desconto  de  10%  do seu salário  bruto  como  contribuição
// para  a  previdência social.  E,  feito  esse  desconto,  são  descontados
// 30% sobre  o  valor  restante  para  vale  alimentação.  Faça um  algoritmo
// que  determine  qual  é  o  salário  líquido  de um funcionário.
Var
salarioBruto, salarioLiquido, descontos : real

Inicio
escreval("Informe o salário bruto do funcionário: ")
leia(salarioBruto)

descontos <- (salarioBruto * 0.10) + (salarioBruto * 0.30)

salarioLiquido <- salarioBruto - descontos

escreval("O salário líquido do funcionário é: ", salarioLiquido)

Fimalgoritmo