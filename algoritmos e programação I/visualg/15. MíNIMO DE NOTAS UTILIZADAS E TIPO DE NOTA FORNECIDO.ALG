Algoritmo "15. Mínimo de notas utilizadas e tipo de nota fornecido"
// Suponha  que  um  caixa  disponha  apenas  notas  de  100,  10  e  1  reais.
// Considerando  que  alguém  está pagando uma compra, faça um algoritmo que
// determine e escreva o número mínimo de notas que o caixa deve  fornecer  como
// troco.  Escreva  também  o  número  de  cada  tipo  de  nota  a  ser
// fornecido  como  troco. Suponha que o sistema monetário não utilize centavos
// (ou seja, o valor da compra é inteiro).

Var
trocoInformado, valor, valor2 : inteiro

Inicio
escreval("Digite o valor do troco: ")
leia(trocoInformado)

valor <- int (trocoInformado / 100)
escreval("Vezes que o valor R$100,00 foi dado como troco: ", valor)
valor2 <- trocoInformado Mod 100

valor <- int (valor2 / 10)
escreval("Vezes que o valor R$10,00 foi dado como troco: ", valor)

valor <- valor2 Mod 10

valor <- int (valor / 1)
escreval("Vezes que o valor R$1,00 foi dado como troco: ", valor)

Fimalgoritmo