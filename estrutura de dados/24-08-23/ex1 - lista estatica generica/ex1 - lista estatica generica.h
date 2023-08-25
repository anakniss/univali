#ifndef EX1_-_LISTA_ESTATICA_GENERICA_H_INCLUDED
#define EX1_-_LISTA_ESTATICA_GENERICA_H_INCLUDED

using namespace std;

template<typename T, int MAX>
struct ListaEstatica
{
    int cardinalidade;
    int elementos[MAX];
};

template<typename T, int MAX>
void criaLista(ListaEstatica<T, MAX> &lista)
{
    lista.cardinalidade = 0;
}

template<typename T, int MAX>
bool ehVazia(ListaEstatica<T, MAX> lista)
{
    return lista.cardinalidade == 0;
}

template<typename T, int MAX>
bool temEspaco(ListaEstatica<T, MAX> lista)
{
    return lista.cardinalidade < MAX;
}

template<typename T, int MAX>
int retornaQuantidade(ListaEstatica<T, MAX> lista)
{
    return lista.cardinalidade;
}

template<typename T, int MAX>
bool verificaElemento(ListaEstatica<T, MAX> lista, int elemento)
{
    for(int i = 0; i < lista.cardinalidade; i++)
    {
        if(lista.elementos[i] == elemento)
            return true;
    }

    return false;
}

template<typename T, int MAX>
int retornaElemento(ListaEstatica<T, MAX> lista, int posicao)
{
    return lista.elementos[posicao - 1];
}

template<typename T, int MAX>
bool verificaPosicao(ListaEstatica<T, MAX> lista, int posicao)
{
    return (posicao > 1 && posicao <= lista.cardinalidade);
}

template<typename T, int MAX>
void insereLista(ListaEstatica<T, MAX> &lista, int elemento, int posicao)
{
    for(int i = lista.cardinalidade; i >= posicao; i--)
        lista.elementos[i] = lista.elementos[i - 1];

    lista.elementos[posicao - 1] = elemento;
    lista.cardinalidade++;
}

template<typename T, int MAX>
void excluiLista(ListaEstatica<T, MAX> lista, int posicao)
{
    for(int i = posicao; i < lista.cardinalidade; i++)
    {
        lista.elementos[i - 1] = lista.elementos[i];
    }

    lista.cardinalidade--;
}

template<typename T, int MAX>
void mostraLista(ListaEstatica<T, MAX> lista)
{
    for(int i = 0; i < lista.cardinalidade; i++)
    {
        cout << lista.elementos[i] << endl;
    }
}

#endif // EX1_-_LISTA_ESTATICA_GENERICA_H_INCLUDED
