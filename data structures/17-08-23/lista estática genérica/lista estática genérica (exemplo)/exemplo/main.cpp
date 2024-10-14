#include <iostream>
#include <cstring>
#include "exemplo.h"

using namespace std;

int main()
{
    cout << "Lista de inteiros..." << endl;

    ListaEstaticaGenerica<int, 10> lista1;

    cria(lista1);

    insere(lista1, 4, 1);
    insere(lista1, 6, 2);
    insere(lista1, 8, 3);
    insere(lista1, 10, 4);

    mostra(lista1);
    retira(lista1, 2);
    mostra(lista1);

    cout << endl; // pular linha

    cout << "Lista de char..." << endl;

    ListaEstaticaGenerica<char, 30> lista2;

    cria(lista2);

    insere(lista2, 'A', 1);
    insere(lista2, 'B', 2);
    insere(lista2, 'C', 3);

    mostra(lista2);

    cout << "eh vazia? " << ehVazia(lista2) << endl;
    cout << "existe elemento? " << existeElemento(lista2, 'X') << endl;

    try {
        int p = umaPosicao(lista2, 'X');
        cout << "O elemento esta na posicao " << p << endl;
    }
    catch (const char* msg) {
        cerr << msg << endl;
    }

    try {
        insere(lista2, 'Y', 10);
    }

    catch(const char* msg){
        if(strcmp(msg, "OVERFLOW") == 0)
            cerr << "ERRO: A lista esta cheia" << endl;
        else if (strcmp(msg, "POSICAO INVALIDA") == 0)
            cerr << "ERRO: A posicao informada nao eh valida" << endl;
        else
            cerr << "ERRO: Ocorreu uma excecao nao tratada" << endl;
    }

    return 0;
}
