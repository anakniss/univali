// MATRIZES - Diagonal principal: Caracteriza-se quando o índice i é igual ao índice j.

#include <iostream>
#include <iomanip>

#define TMAX 5

using namespace std;

int main()
{
    int numeros[TMAX][TMAX] = { {0} };

    srand(time(NULL));

    cout << "Preenchendo matriz..." << endl;

    for (int i = 0; i < TMAX; i++) {
        for (int j = 0; j < TMAX; j++) {
            numeros[i][j] = rand() % 10;
        }
    }

    cout << "\nMostrando matriz inteira...\n" << endl; 

    for (int i = 0; i < TMAX; i++) {
        for (int j = 0; j < TMAX; j++) {
            cout << numeros[i][j] << "\t";
        }

        cout << endl;
    }

    cout << "\nMostrando valores da diagonal principal...\n" << endl;

    for (int i = 0; i < TMAX; i++) {
        for (int j = 0; j < TMAX; j++) {
            if (i == j) {
                cout << "valor da diagonal principal: " << numeros[i][j] << endl;
            }
        }
    }
}

