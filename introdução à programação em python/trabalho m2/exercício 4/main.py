from passageiro import Passageiro
import funcoesPassageiros

def main():
    capacidadeMaxima = 1300
    listaPassageiro = []

    while True:
        print("1 - Adicionar novo passageiro")
        print("2 - Apresentar peso total dos passageiros")
        print("3 - Sair")

        opcao = int(input("Escolha uma opção: "))

        if opcao == 1:
            nome = input("Digite o nome do passageiro: ")
            peso = float(input("Digite o peso do passageiro em kg: "))
            passageiro = Passageiro(nome, peso)
            funcoesPassageiros.adicionaPassageiro(listaPassageiro, passageiro)
            print("Passageiro adicionado à lista.")

        elif opcao == 2:
            pesoTotal = funcoesPassageiros.calculaPesoTotal(listaPassageiro)
            print("Peso total dos passageiros:", pesoTotal, "kg")
            if pesoTotal > capacidadeMaxima:
                print("Limite de peso suportado excedido.")
            else:
                print("Dentro do limite de peso suportado.")

        elif opcao == 3:
            break

if __name__ == '__main__':
    main()
