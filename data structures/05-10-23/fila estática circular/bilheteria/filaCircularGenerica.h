#ifndef BILHETERIA_H_INCLUDED
#define BILHETERIA_H_INCLUDED

#include <iostream>

using namespace std;

/*Elabore uma unidade sintática para representar uma estrutura de fila estática e operações e relações
para criar uma fila, verificar se uma fila está vazia, verificar se há espaço na fila, recuperar o número
de elementos da fila, verificar se um determinado elemento está na fila, verificar se uma posição
qualquer é válida, recuperar um elemento da fila, recuperar a posição de um elemento da fila,
recuperar o primeiro elemento da fila, recuperar o último elemento da fila, inserir um elemento,
retirar um elemento e exibir os elementos da fila.
Admita que os elementos da referida estrutura de dados possam ser de quaisquer tipos.
Utilize uma variável indexada unidimensional para representar a estrutura de dados.
Considere a representação circular de fila.*/

template<typename T, int MAX>
struct FilaCircular {
	T elementos[MAX];
	int inicio;
	int fim;
	int cardinalidade;
};

template<typename T, int MAX>
void cria(FilaCircular<T, MAX>& fila) {
	fila.inicio = MAX - 1;
	fila.fim = MAX - 1;
	fila.cardinalidade = 0;
}

template<typename T, int MAX>
bool ehVazia(FilaCircular<T, MAX> fila) {
	return fila.cardinalidade == 0;
}

template<typename T, int MAX>
bool temEspaco(FilaCircular<T, MAX> fila) {
	return fila.cardinalidade < MAX;
}

template<typename T, int MAX>
int numeroElementos(FilaCircular<T, MAX> fila) {
	return fila.cardinalidade;
}

template<typename T, int MAX>
bool existeElemento(FilaCircular<T, MAX> fila, T elemento) {
	int posicao = fila.inicio;
	for (int i = 0; i < fila.cardinalidade; i++) {
		if (fila.elementos[posicao] == elemento) {
			return true;
		}
		if (posicao > MAX - 1) {
			posicao = 0;
		}
		posicao++;
	}

	return false;
}

template<typename T, int MAX>
bool existePosicao(FilaCircular<T, MAX> fila, int posicao) {
	return ((posicao > 0) && (posicao <= fila.cardinalidade));
}

template<typename T, int MAX>
T recuperaElemento(FilaCircular<T, MAX> fila, int posicao) {
	if (posicao < 1 && posicao > fila.cardinalidade) {
		throw "Posicao invalida";
	}

	if ((posicao + fila.inicio) <= MAX - 1) {
		return fila.elementos[posicao + fila.inicio];
	}
	else {
		return fila.elementos[posicao - MAX + fila.inicio];
	}
}

template<typename T, int MAX>
int posicao(FilaCircular<T, MAX> fila, T elemento) {
	if (!existeElemento(fila, elemento)) {
		throw "Elemento nao existe na fila";
	}

	int posicao = fila.inicio;

	for (int i = 0; i < fila.cardinalidade; i++) {
		posicao++;
		if (posicao > MAX - 1) {
			posicao = 0;
		}
		if (fila.elementos[posicao] == elemento) {
			return posicao;
		}
	}

	return false;
}

template<typename T, int MAX>
T primeiro(FilaCircular<T, MAX> fila) {
	if (fila.inicio < MAX - 1) {
		return fila.elementos[fila.inicio + 1];
	}
	else {
		return fila.elementos[0];
	}
}

template<typename T, int MAX>
T ultimo(FilaCircular<T, MAX> fila) {
	return fila.elementos[fila.fim];
}

template<typename T, int MAX>
void insere(FilaCircular<T, MAX>& fila, T elemento) {
	if (fila.cardinalidade > MAX - 1) {
		throw "OVERFLOW";
	}

	fila.fim++;

	if (fila.fim > MAX - 1) {
		fila.fim = 0;
	}
	fila.elementos[fila.fim] = elemento;
	fila.cardinalidade++;
}

template<typename T, int MAX>
void remove(FilaCircular<T, MAX>& fila) {
	if (fila.cardinalidade == 0) {
		throw "UNDERFLOW";
	}

	fila.inicio++;

	if (fila.inicio >= MAX - 1) {
		fila.inicio = 0;
	}
	fila.cardinalidade--;
}

template<typename T, int MAX>
void mostra(FilaCircular<T, MAX>& fila) {
	if (fila.cardinalidade == 0) {
		throw "UNDERFLOW";
	}

	int posicao = fila.inicio + 1;

	for (int i = posicao; i < fila.cardinalidade; i++) {
		if (posicao >= fila.cardinalidade) {
			posicao = 0;
		}

		cout << "----------------" << endl;
		cout << "Elemento: " << fila.elementos[i] << endl;
	}

	cout << "Cardinalidade: " << fila.cardinalidade << endl;
	cout << "Inicio: " << fila.inicio << endl;
	cout << "Fim: " << fila.fim << endl;
}

#endif // BILHETERIA_H_INCLUDED
