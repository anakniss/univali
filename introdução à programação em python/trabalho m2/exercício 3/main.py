import listaFuncoes

def main():
    listaNumeros = []

    while True:
        print("1 - Adicionar número à lista")
        print("2 - Obter primeiro elemento")
        print("3 - Obter último elemento")
        print("4 - Obter quantidade de elementos entre o primeiro e o último")
        print("5 - Sair")

        opcao = int(input("Escolha uma opção: "))

        if opcao == 1:
            numero = int(input("Digite um número: "))
            listaFuncoes.adicionaNumeroLista(listaNumeros, numero)
            print("Número adicionado à lista.")

        elif opcao == 2:
            primeiroElemento = listaFuncoes.getPrimeiroElemento(listaNumeros)
            if primeiroElemento is not None:
                print("Primeiro elemento: ", primeiroElemento)
            else:
                print("A lista está vazia.")

        elif opcao == 3:
            ultimoElemento = listaFuncoes.getUltimoElemento(listaNumeros)
            if ultimoElemento is not None:
                print("Último elemento: ", ultimoElemento)
            else:
                print("A lista está vazia.")

        elif opcao == 4:
            meioElementos = listaFuncoes.getElementosEntrePrimeiroUltimo(listaNumeros)
            if meioElementos is not None:
                print("Quantidade de elementos entre o primeiro e o último: ", meioElementos)
            else:
                print("A lista contém menos de dois elementos.")

        elif opcao == 5:
            break

        print()

if __name__ == '__main__':
    main()
