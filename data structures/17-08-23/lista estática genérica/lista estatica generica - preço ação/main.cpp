#include <iostream>
#include<time.h>
#include "ex1 - lista estatica generica.h"
#define MAX 20

using namespace std;

int main()
{
    ListaEstaticaGenerica<int, MAX> lista;

    cria(lista);
    int minutos = 0;

    insere(lista, rand()%2 + 5, 1);

    while (minutos < 380) {
        cout << "Lista a " << minutos << " minutos" << endl;
        minutos += 20;
        insere(lista, rand()%6 - 3, numeroDeElementos(lista) + 1);
        //cout << "Minutos antes: " << minutos << endl;
        //insere(lista, 0, 1);
        //cout << "Minutos depois: " << minutos << endl;
        mostra(lista);
    }

    cout << "\n===============================" << endl;
    cout << "LISTA FINAL" << endl;
    cout << "===============================" << endl;
    mostra(lista);

    return 0;
}
