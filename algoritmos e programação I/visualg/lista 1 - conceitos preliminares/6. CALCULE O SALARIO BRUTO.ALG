Algoritmo "Calcule o sal�rio bruto"
//6. Escreva um algoritmo que leia o n�mero de horas trabalhadas mensais de
//um funcion�rio, o valor que recebe por hora e o n�mero de dependentes.
//Calcule o sal�rio bruto deste funcion�rio, sabendo que cada
//dependente acrescenta 10% ao sal�rio.
Var
// Se��o de Declara��es das vari�veis

 dependentes: inteiro
 
 horas, valor_horas, salario_bruto, qntd_dependentes, num_dep: real

Inicio
// Se��o de Comandos, procedimento, fun��es, operadores, etc...

    num_dep <- 0.10

    Escreval("Informe o n�mero de horas trabalhadas mensais: ")
    Leia(horas)
    
    Escreval("Informe o valor que a ser recebido por hora trabalhada: ")
    Leia(valor_horas)
    
    Escreval("Informe o n�mero de dependentes: ")
    Leia(qntd_dependentes)
    
    salario_bruto <- horas * valor_horas
    
    num_dep <- num_dep * qntd_dependentes
    
    num_dep <- num_dep * salario_bruto
    
    salario_bruto <- salario_bruto + num_dep
    
    Escreva("O valor bruto deste funcion�rio � de: R$", salario_bruto:6:2)
    
    

Fimalgoritmo