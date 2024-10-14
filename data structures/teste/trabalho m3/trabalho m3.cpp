#include <iostream>
#include <vector>
#include <cstdlib>
#include <fstream>
#include "ordenacoes.h"
#include "genericos.h"
#include "dicionario.h"

using namespace std;

int main()
{
	ifstream arquivo;
	string nomeArquivo;
	int opcao, quantidadeDados, comparacoes = 0, movimentacoes = 0;

	do {
		mostraMenu();
		opcao = leiaNumero("Digite a opcao desejada: ");

		// dados_ordem_crescente.txt
		criaArquivo();

		try {

			cout << "Digite o caminho e o nome do arquivo: ";
			cin >> nomeArquivo;

			arquivo.open(nomeArquivo);

			if (!arquivo.is_open()) {
				cout << "Erro ao abrir o arquivo. Verifique o caminho e o nome informados." << endl;
				return 1;
			}

			vector<int> dados;
			int dadoLido;

			while (arquivo >> dadoLido) {
				dados.push_back(dadoLido);
			}

			arquivo.close();

			cout << "Arquivo carregado com sucesso" << endl;


			while (true) {
				cout << "\n Quantidade de dados para ordenacao (1 - 10000, 0 para sair)";
				cin >> quantidadeDados;

				if (quantidadeDados == 0) {
					break;
				}

				if (quantidadeDados < 1 || quantidadeDados > 10000) {
					cout << "Quantidade de dados invalida. Insira um valor entre 1 e 10000." << endl;
					continue;
				}

				vector<int> dadosOrdenacao(dados.begin(), dados.begin() + quantidadeDados);

				int tipoOrdenacao;
				cout << "Escolha o tipo de ordenacao inicial:" << endl;
				cout << "1 - Crescente" << endl;
				cout << "2 - Decrescente" << endl;
				cout << "3 - Aleatoria" << endl;
				tipoOrdenacao = leiaNumero("Digite a opcao desejada: ");

				geraDadosIniciais<int>(tipoOrdenacao, dadosOrdenacao, comparacoes, movimentacoes);

				comparacoes = 0;
				movimentacoes = 0;

			}
		}
		catch (const char* msg) {
			cerr << msg << endl;
		}

	} while (opcao != 6);

	return 0;
}


