Algoritmo "8. Calcule a distância entre os pontos"
//Faça  um  algoritmo  que  leia  as  coordenadas  de  dois  pontos,  P1  (x1,
// y1)  e  P2  (x2,  y2)  respectivamente,  e calcule a distância entre eles.
Var
coordenada1, coordenada2, ponto1, ponto2, distancia : real

Inicio
escreval("Ponto 1 - Informe a primeira coordenada: ")
leia(coordenada1)

escreval("Ponto 1 - Informe a segunda coordenada: ")
leia(coordenada2)

ponto1 <- coordenada2 - coordenada1

escreval("Ponto 2 - Informe a primeira coordenada: ")
leia(coordenada1)

escreval("Ponto 2 - Informe a segunda coordenada: ")
leia(coordenada2)

ponto2 <- coordenada2 - coordenada1

distancia <- raizq((ponto1 ^ 2) + (ponto2 ^ 2))

escreval("A distância entre os  dois pontos é: ", distancia)

Fimalgoritmo