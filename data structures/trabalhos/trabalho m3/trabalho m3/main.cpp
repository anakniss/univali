#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

template<typename T>
void insertionSort(vector<T>& lista)
{
	int n = lista.size();
	for (int i = 1; i < n; i++) {
		auto chave = lista[i];
		int j = i - 1;

		while (j >= 0 && chave < lista[j]) {
			lista[j + 1] = lista[j];
			j--;
		}
		lista[j + 1] = chave;
	}
}

template<typename T>
void shellSort(vector<T>& lista) {
	int n = lista.size();

	for (int gap = n / 2; gap > 0; gap /= 2) {
		for (int i = gap; i < n; i++) {
			T temp = lista[i];
			int j;

			for (j = i; j >= gap && lista[j - gap] > temp; j -= gap) {
				lista[j] = lista[j - gap];
			}
			lista[j] = temp;
		}
	}
}

template<typename T>
T partition(vector<T>& lista, int inicio, int fim) {
	auto pivot = lista[fim];
	int i = inicio;
	for (int j = inicio; j < fim; j++) {
		if (lista[j] >= pivot) {
			swap(lista[j], lista[i]);
			i = i + 1;
		}
	}
	swap(lista[i], lista[fim]);
	return i;
}


template<typename T>
void quickSort(vector<T>& lista, int inicio, int fim) {
	if (inicio < fim) {
		auto p = partition(lista, inicio, fim);
		quickSort(lista, inicio, p - 1);
		quickSort(lista, p + 1, fim);
	}
}

int main()
{
	vector<int> num;


	for (int i = 0; i < 10; i++) {
		num.push_back(rand() % 10);
	}

	cout << "Vetor desordenado: ";
	for (int i = 0; i < 10; i++) {
		cout << num[i] << " ";
	}

	//insertionSort<int>(num);
	//shellSort<int>(num);
	int n = num.size();
	quickSort(num, 0, n - 1);

	cout << "\nVetor ordenado: ";
	for (int val : num) {
		cout << val << " ";
	}
	cout << endl;

	return 0;
}
