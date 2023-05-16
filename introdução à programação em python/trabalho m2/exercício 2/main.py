from calculaCusto import calculaCusto

custo_fabrica = float(input("Digite o custo de fábrica do carro: "))
custo_consumidor = calculaCusto(custo_fabrica)
print("O custo ao consumidor do carro é R${:.2f}".format(custo_consumidor))