Algoritmo "Calcule o comprimento da hipotenusa"
//4. Fa�a um algoritmo que leia o comprimento dos catetos de um tri�ngulo
// ret�ngulo e calcule o comprimento da hipotenusa.
//F�RMULA: h^2 = a^2 + b^2

Var
// Se��o de Declara��es das vari�veis 

   cata, catb, hipotenusa, hipotenusa_dois: real

Inicio
// Se��o de Comandos, procedimento, fun��es, operadores, etc... 

   Escreva("Informe o cateto oposto: ")
   Leia(cata)
   
   Escreva("Informe o cateto adjacente: ")
   Leia(catb)
   
   hipotenusa <- (cata * cata) + (catb * catb)
   hipotenusa_dois <- RaizQ(hipotenusa)
   
   Escreva("O comprimento da hipotenusa �: ", hipotenusa_dois:6:2)

Fimalgoritmo