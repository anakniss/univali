Algoritmo "10. Calcule o sal�rio l�quido do funcion�rio com descontos"
// Considere  que  o  sal�rio  l�quido  de  um  funcion�rio  �  calculado
// atrav�s  de  um  desconto  de  10%  do seu sal�rio  bruto  como  contribui��o
// para  a  previd�ncia social.  E,  feito  esse  desconto,  s�o  descontados
// 30% sobre  o  valor  restante  para  vale  alimenta��o.  Fa�a um  algoritmo
// que  determine  qual  �  o  sal�rio  l�quido  de um funcion�rio.
Var
salarioBruto, salarioLiquido, descontos : real

Inicio
escreval("Informe o sal�rio bruto do funcion�rio: ")
leia(salarioBruto)

descontos <- (salarioBruto * 0.10) + (salarioBruto * 0.30)

salarioLiquido <- salarioBruto - descontos

escreval("O sal�rio l�quido do funcion�rio �: ", salarioLiquido)

Fimalgoritmo