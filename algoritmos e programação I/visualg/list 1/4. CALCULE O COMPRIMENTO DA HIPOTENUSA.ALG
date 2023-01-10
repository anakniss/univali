Algoritmo "Calcule o comprimento da hipotenusa"
//4. Faça um algoritmo que leia o comprimento dos catetos de um triângulo
// retângulo e calcule o comprimento da hipotenusa.
//FÓRMULA: h^2 = a^2 + b^2

Var
// Seção de Declarações das variáveis 

   cata, catb, hipotenusa, hipotenusa_dois: real

Inicio
// Seção de Comandos, procedimento, funções, operadores, etc... 

   Escreva("Informe o cateto oposto: ")
   Leia(cata)
   
   Escreva("Informe o cateto adjacente: ")
   Leia(catb)
   
   hipotenusa <- (cata * cata) + (catb * catb)
   hipotenusa_dois <- RaizQ(hipotenusa)
   
   Escreva("O comprimento da hipotenusa é: ", hipotenusa_dois:6:2)

Fimalgoritmo