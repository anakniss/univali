Algoritmo "semnome"
// Disciplina   : [Linguagem e Lógica de Programação]
// Professor   : Antonio Carlos Nicolodi 
// Descrição   : Aqui você descreve o que o programa faz! (função)
// Autor(a)    : Nome do(a) aluno(a)
// Data atual  : 04/09/2022
Var
   altura, peso: real


Inicio
// Seção de Comandos, procedimento, funções, operadores, etc... 
   ESCREVAL ("Digite a altura: ")
   LEIA (altura)
   ESCREVAL ("Digite o peso: ")
   LEIA (peso)
   
   SE (peso < 65) ou (peso > 100) e (altura < 1.70) ou (altura > 1.95) ENTAO
       ESCREVAL ("Totalmente Recusado")
   SENAO
        SE (altura < 1.70) ou (altura > 1.95) ENTAO
           ESCREVAL("Recusado por altura")
        SENAO
           SE (peso < 65) ou (peso > 100) ENTAO
              ESCREVAL("Recusado por peso")
           SENAO
             SE (peso >= 65) e (peso <= 100) e (altura >= 1.70) e (altura <= 1.95)ENTAO
                ESCREVAL ("Aceito!")
             FIMSE
          FIMSE
       FIMSE
   FIMSE
Fimalgoritmo