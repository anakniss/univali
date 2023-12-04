#ifndef ORDENACOES_H_INCLUDED
#define ORDENACOES_H_INCLUDED

#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

// MÉTODOS DE ORDENAÇÃO DECRESCENTE

template<typename T>
void insertionSortDecrescente(vector<T>& lista, int& comparacoes, int& movimentacoes)
{
	int n = lista.size();
	for (int i = 1; i < n; i++) {
		auto chave = lista[i];
		int j = i - 1;

		comparacoes++;
		while (j >= 0 && chave > lista[j]) {
			lista[j + 1] = lista[j];
			j--;
			movimentacoes++;
			comparacoes++;
		}
		lista[j + 1] = chave;
		movimentacoes++;
	}
}

template<typename T>
void shellSortDecrescente(vector<T>& lista, int& comparacoes, int& movimentacoes) {
	int n = lista.size();

	for (int gap = n / 2; gap > 0; gap /= 2) {
		for (int i = gap; i < n; i++) {
			T temp = lista[i];
			int j;

			comparacoes++;
			for (j = i; j >= gap && lista[j - gap] < temp; j -= gap) {
				lista[j] = lista[j - gap];
				movimentacoes++;
				comparacoes++;
			}
			lista[j] = temp;
			movimentacoes++;
		}
	}
}

template<typename T>
T partitionDecrescente(vector<T>& lista, int inicio, int fim, int& comparacoes, int& movimentacoes) {
	auto pivot = lista[fim];
	int i = inicio;
	for (int j = inicio; j < fim; j++) {
		comparacoes++;
		if (lista[j] <= pivot) {
			swap(lista[j], lista[i]);
			i = i + 1;
			movimentacoes++;
		}
	}
	swap(lista[i], lista[fim]);
	movimentacoes++;
	return i;
}

template<typename T>
void quickSortDecrescente(vector<T>& lista, int inicio, int fim, int& comparacoes, int& movimentacoes) {
	if (inicio < fim) {
		auto p = partition(lista, inicio, fim);
		quickSort(lista, inicio, p - 1);
		quickSort(lista, p + 1, fim);
	}
}

// MÉTODOS DE ORDENAÇÃO CRESCENTE

template<typename T>
void insertionSortCrescente(vector<T>& lista, int& comparacoes, int& movimentacoes)
{
	int n = lista.size();
	for (int i = 1; i < n; i++) {
		auto chave = lista[i];
		int j = i - 1;

		while (j >= 0 && chave < lista[j]) {
			lista[j + 1] = lista[j];
			j--;
			movimentacoes++;
			comparacoes++;
		}
		lista[j + 1] = chave;
		movimentacoes++;
	}
}

template<typename T>
void shellSortCrescente(vector<T>& lista, int& comparacoes, int& movimentacoes) {
	int n = lista.size();

	for (int gap = n / 2; gap > 0; gap /= 2) {
		for (int i = gap; i < n; i++) {
			T temp = lista[i];
			int j;

			comparacoes++;
			for (j = i; j >= gap && lista[j - gap] > temp; j -= gap) {
				lista[j] = lista[j - gap];
				movimentacoes++;
				comparacoes++;
			}
			lista[j] = temp;
			movimentacoes++;
		}
	}
}

template<typename T>
T partitionCrescente(vector<T>& lista, int inicio, int fim, int& comparacoes, int& movimentacoes) {
	auto pivot = lista[fim];
	int i = inicio;
	for (int j = inicio; j > fim; j++) {
		comparacoes++;
		if (lista[j] <= pivot) {
			swap(lista[j], lista[i]);
			i = i + 1;
			movimentacoes++;
		}
	}
	swap(lista[i], lista[fim]);
	movimentacoes++;
	return i;
}

template<typename T>
void quickSortCrescente(vector<T>& lista, int inicio, int fim, int& comparacoes, int& movimentacoes){
	if (inicio < fim) {
		auto p = partition(lista, inicio, fim);
		quickSort(lista, inicio, p - 1);
		quickSort(lista, p + 1, fim);
	}
}

template<typename T>
void geraDadosIniciais(int tipoOrdenacao, vector<T>& dadosOrdenacao, int comparacoes, int movimentacoes) {
	int tam = dadosOrdenacao.size();
	if (tipoOrdenacao == 1) {
		shellSortCrescente<T>(dadosOrdenacao, comparacoes, movimentacoes);
		cout << "ORDEM CRESCENTE" << endl;
		for (int j = 0; j < tam; j++) {
			cout << dadosOrdenacao[j] << " ";
		}
		cout << "comparacoes: " << comparacoes << endl;
		cout << "movimentacoes: " << movimentacoes << endl;
	}
	if (tipoOrdenacao == 2) {
		shellSortDecrescente<T>(dadosOrdenacao, comparacoes, movimentacoes);
		cout << "ORDEM DECRESCENTE" << endl;
		for (int j = 0; j < tam; j++) {
			cout << dadosOrdenacao[j] << " ";
		}
		cout << "comparacoes: " << comparacoes << endl;
		cout << "movimentacoes: " << movimentacoes << endl;
	}
	if (tipoOrdenacao == 3) {
		int n = dadosOrdenacao.size();
		int aux;

		for (int i = n; i > 0; i--) {
			aux = rand() % i;
			dadosOrdenacao.push_back(dadosOrdenacao[aux]);
			dadosOrdenacao.erase(dadosOrdenacao.begin() + i);
		}
		
		dadosOrdenacao.push_back(dadosOrdenacao[0]);
		dadosOrdenacao.erase(dadosOrdenacao.begin());

		cout << "ORDEM ALEATORIA" << endl;
		for (int j = 0; j < tam; j++) {
			cout << dadosOrdenacao[j] << " ";
		}
	}
}

#endif // ORDENACOES_H_INCLUDED
