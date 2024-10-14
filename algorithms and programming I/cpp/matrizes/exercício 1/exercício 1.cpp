#include <iostream>

using namespace std;
//Multiplicação de matrizes

const int R1 = 2;
const int C1 = 2;
const int R2 = 2;
const int C2 = 2;

int main()
{
	int matrizA[R1][C1] = { {1, 1}, {2, 2} },
		matrizB[R2][C1] = { {1, 1}, {2, 2} };

	int resultado[R2][C2];

	if (C1 != R2) {
		cout << "A quantidade de colunas da primeira matriz deve ser igual a quantidade de linhas da segunda matriz" << endl;
	}
	else {
		for (int i = 0; i < R1; i++) {
			for (int j = 0; j < C2; j++) {
				resultado[i][j] = 0;
				for (int k = 0; k < R2; k++) {
					resultado[i][j] += matrizA[i][k] * matrizB[k][j];
				}
				cout << resultado[i][j] << "\t";
			}
			cout << endl;
		}
	}
}
