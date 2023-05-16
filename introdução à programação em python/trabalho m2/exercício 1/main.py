from calculaDistancia import calculaDistancia

x1 = float(input("Digite o valor de x1: "))
y1 = float(input("Digite o valor de y1: "))
x2 = float(input("Digite o valor de x2: "))
y2 = float(input("Digite o valor de y2: "))

distance = calculaDistancia(x1, y1, x2, y2)

print("A distância entre os pontos P({},{}) e P({},{}) é {:.2f}".format(x1, y1, x2, y2, distance))
