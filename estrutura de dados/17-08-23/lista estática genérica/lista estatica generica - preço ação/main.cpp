#include <iostream>
#include<time.h>
#include "ex1 - lista estatica generica.h"
#define MAX 20

using namespace std;

int main()
{
    ListaEstaticaGenerica<int , MAX> lista;

    cria(lista);

    insereLista(lista, rand()%3 + 5, 0);

    for(int i = 1; i < 20; i++)
    {
        insereLista(lista, lista.elementos[i]  i);
    }

    mostraLista(lista);

    return 0;
}
