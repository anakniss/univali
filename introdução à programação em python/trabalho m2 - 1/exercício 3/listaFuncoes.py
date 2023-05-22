def adicionaNumeroLista(listaNumeros, numero):
    listaNumeros.append(numero)

def getPrimeiroElemento(listaNumeros):
    if len(listaNumeros) > 0:
        return listaNumeros[0]
    else:
        return None

def getUltimoElemento(listaNumeros):
    if len(listaNumeros) > 0:
        return listaNumeros[-1]
    else:
        return None

def getElementosEntrePrimeiroUltimo(listaNumeros):
    if len(listaNumeros) < 2:
        return None
    else:
        return len(listaNumeros) - 2