// 2. Faça um algoritmo que calcule o volume de uma lata de óleo.
// FÓRMULA: volume = p * raio2
// * altura

 Algoritmo "Calcule o volume de uma lata de óleo"
 
 Var
 
 volume, raio, altura: real
 
 Inicio
 
    escreval("Digite o raio: ")
    leia(raio)
    
    escreval("Digite a altura: ")
    leia(altura)
 
    volume <- pi * (raio * raio) * altura
    
    escreva("O volume da lata de óleo é: ", volume:6:2)
 
 


 FimAlgoritmo