#include <iostream>

using namespace std;
#define TMAX 10

//Pesquisa de elemento

int main()
{
    int numeros[TMAX] = {1, 2, 3, 4, 1, 6, 7, 8, 1, 10};
    int i = 0;
    int elemento;
    bool encontrou = false;

    cout << "Digite o elemento que deseja procurar: ";
    cin >> elemento;

    while(i < TMAX && not(encontrou)){
        if(numeros[i] == elemento){
            encontrou = true;
        }
        else {
            i++;
        }
    }

    if(encontrou) {
        cout << "Encontrado na posição " << i;
    }
    else {
        cout << "Elemento não encontrado";
    }
}
