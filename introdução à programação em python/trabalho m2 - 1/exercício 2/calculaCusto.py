def calculaCusto(custoFabrica):
    percentualDistribuidor = 0.28
    impostos = 0.45

    custoConsumidor = custoFabrica + (custoFabrica * percentualDistribuidor) + (custoFabrica * impostos)
    return custoConsumidor