//Desenvolva um c�digo utilizando matrizes, aonde uma sala tem 5 alunos e cada um tem 3 notas e uma m�dia. Leia as notas de todos os alunos e calcule a nota de cada um, colocando-as na matriz.

#include <iostream>
#include <iomanip>
#define TCOLUNAMAX 4
#define TLINHAMAX 5

using namespace std;

int main()
{
    float notas[TLINHAMAX][TCOLUNAMAX], soma;

    //Gera valores aleat�rios
    srand(time(NULL));

    for (int i = 0; i < TLINHAMAX; i++) {
        soma = 0;
        for (int j = 0; j < TCOLUNAMAX; j++) {
            if (j < TCOLUNAMAX - 1) {
                //Retorna um valor aleat�rio de 0 a 9
                notas[i][j] = rand() % 10;
                soma += notas[i][j];
            }
            else {
                notas[i][j] = soma / (TCOLUNAMAX - 1);
            }
        }
    }

    for (int i = 0; i < TLINHAMAX; i++) {
        for (int j = 0; j < TCOLUNAMAX; j++) {
            cout << notas[i][j] << "\t"; 
        }

        cout << endl; 
    }
}

