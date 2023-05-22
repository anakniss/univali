def adicionaPassageiro(listaPassageiro, passageiro):
    listaPassageiro.append(passageiro)

def calculaPesoTotal(listaPassageiro):
    pesoTotal = sum(passageiro.peso for passageiro in listaPassageiro)
    return pesoTotal
