Algoritmo "Calcule o salário bruto"
//6. Escreva um algoritmo que leia o número de horas trabalhadas mensais de
//um funcionário, o valor que recebe por hora e o número de dependentes.
//Calcule o salário bruto deste funcionário, sabendo que cada
//dependente acrescenta 10% ao salário.
Var
// Seção de Declarações das variáveis

 dependentes: inteiro
 
 horas, valor_horas, salario_bruto, qntd_dependentes, num_dep: real

Inicio
// Seção de Comandos, procedimento, funções, operadores, etc...

    num_dep <- 0.10

    Escreval("Informe o número de horas trabalhadas mensais: ")
    Leia(horas)
    
    Escreval("Informe o valor que a ser recebido por hora trabalhada: ")
    Leia(valor_horas)
    
    Escreval("Informe o número de dependentes: ")
    Leia(qntd_dependentes)
    
    salario_bruto <- horas * valor_horas
    
    num_dep <- num_dep * qntd_dependentes
    
    num_dep <- num_dep * salario_bruto
    
    salario_bruto <- salario_bruto + num_dep
    
    Escreva("O valor bruto deste funcionário é de: R$", salario_bruto:6:2)
    
    

Fimalgoritmo