
Algoritmo "Calcule a �rea do tri�ngulo"

Var

   ladoa, ladob, ladoc, p, area: real
   
   
Inicio

      Escreva("Digite o valor do lado a: ")
      Leia (ladoa)

      Escreva("Digite o valor do lado b: ")
      Leia (ladob)

      Escreva("Digite o valor do lado c: ")
      Leia (ladoc)
      
      
      p <- (ladoa + ladob + ladoc) / 2
      
      area <- RaizQ(p * (p - ladoa) * (p - ladob) * (p - ladoc))
      
      Escreva("A �rea do tri�ngulo �: ", area:6:2)

FimAlgoritmo

