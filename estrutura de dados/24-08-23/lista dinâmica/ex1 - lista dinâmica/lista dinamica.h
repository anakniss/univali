#ifndef LISTA_DINAMICA_H_INCLUDED
#define LISTA_DINAMICA_H_INCLUDED

using namespace std;

template<typename T>
struct Nodo
{
    T elemento;
    Nodo<T> *proximo;
};

template<typename T>
struct ListaDinamica
{
    int cardinalidade;
    Nodo<T> *inicio;
};

void cria(ListaDinamica &lista)
{
    lista.cardinalidade = 0;
    lista.inicio = NULL;
}

void destroi(ListaDinamica &lista)
{
    Nodo<T> *p;
    while(lista.inicio != NULL)
    {
        p = lista.inicio;
        lista.inicio
    }
}

#endif // LISTA_DINAMICA_H_INCLUDED
