#include <iostream>
#include "lista estatica.h"

using namespace std;

int main()
{
    ListaEstatica lista, lista2;
    int i, n, elemento;

    lista = criaLista();
    lista2 = criaLista();

    cout << "Informe a quantidade de itens que gostaria de inserir na lista: ";
    cin >> n;

    for(i = 1; i <= n; i++)
    {
        cout << "Informe o elemento " << i << " da lista: ";
        cin >> elemento;

        insereLista(lista, elemento, i);
    }

    mostraLista(lista);
    cout << endl;

    cout << "Informe a quantidade de itens que gostaria de inserir na lista: ";
    cin >> n;

    for(i = 1; i <= n; i++)
    {
        cout << "Informe o elemento " << i << " da lista: ";
        cin >> elemento;

        insereLista(lista2, elemento, i);
    }

    mostraLista(lista2);
    cout << endl;

    for(i = 1; i <= retornaQuantidade(lista); i++)
    {
        if(verificaElemento(lista2, retornaElemento(lista, i)))
            cout << retornaElemento(lista, i) << " eh comum nas listas" << endl;
    }

    return 0;
}
