#ifndef EX1_H_INCLUDED
#define EX1_H_INCLUDED

#include <iostream>

using namespace std;

template <typename T>
struct Nodo {
    T elemento;
    Nodo<T> *proximo;
};

template <typename T>
struct ListaSimplesmentEncadeada{
    int cardinalidade;
    Nodo<T> *inicio;
};

template <typename T>
void cria(ListaSimplesmentEncadeada<T> &lista){
    lista.cardinalidade = 0;
    lista.inicio = NULL;
}

template <typename T>
void destroi(ListaSimplesmentEncadeada<T> &lista){
    Nodo<T> *p;
    while(lista.inicio != NULL){
        p = lista.inicio;
        lista.inicio = lista.inicio->proximo;
        delete p;
    }
    lista.cardinalidade = 0;
}


#endif // EX1_H_INCLUDED
