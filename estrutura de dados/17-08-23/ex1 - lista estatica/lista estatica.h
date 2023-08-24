#ifndef LISTA_ESTATICA_H_INCLUDED
#define LISTA_ESTATICA_H_INCLUDED

using namespace std;

const int tamanho = 100;

struct ListaEstatica
{
    int cardinalidade;
    int elementos[tamanho];
};

ListaEstatica criaLista()
{
    ListaEstatica lista;

    lista.cardinalidade = 0;
    return lista;
}


bool ehVazia(ListaEstatica lista)
{
    return lista.cardinalidade == 0;
}

bool temEspaco(ListaEstatica lista)
{
    return lista.cardinalidade < tamanho;
}

int retornaQuantidade(ListaEstatica lista)
{
    return lista.cardinalidade;
}

bool verificaElemento(ListaEstatica lista, int elemento)
{
    for(int i = 0; i < lista.cardinalidade; i++)
    {
        if(lista.elementos[i] == elemento)
            return true;
    }

    return false;
}

int retornaElemento(ListaEstatica lista, int posicao)
{
    return lista.elementos[posicao - 1];
}

bool verificaPosicao(ListaEstatica lista, int posicao)
{
    return (posicao > 1 && posicao <= lista.cardinalidade);
}

void insereLista(ListaEstatica &lista, int elemento, int posicao)
{
    for(int i = lista.cardinalidade; i >= posicao; i--)
        lista.elementos[i] = lista.elementos[i - 1];

    lista.elementos[posicao - 1] = elemento;
    lista.cardinalidade++;
}

void excluiLista(ListaEstatica lista, int posicao)
{
    for(int i = posicao; i < lista.cardinalidade; i++)
    {
        lista.elementos[i - 1] = lista.elementos[i];
    }

    lista.cardinalidade--;
}

void mostraLista(ListaEstatica lista)
{
    cout << "LISTA" << endl;
    for(int i = 0; i < lista.cardinalidade; i++)
    {
        cout << lista.elementos[i] << endl;
    }
}



#endif // LISTA_ESTATICA_H_INCLUDED
