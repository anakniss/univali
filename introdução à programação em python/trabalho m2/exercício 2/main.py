from calculaCusto import calculaCusto

custoFabrica = float(input("Digite o custo de fábrica do carro: "))
custoConsumidor = calculaCusto(custoFabrica)
print("O custo ao consumidor do carro é R${:.2f}".format(custoConsumidor))