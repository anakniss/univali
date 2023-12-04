#ifndef DICIONARIO_H_INCLUDED
#define DICIONARIO_H_INCLUDED

#include "associacoes.h"

#include <list>
using namespace std;

typedef int (FuncaoHash)(int);

template<int tamanho, typename T>
struct Dicionario
{
    int numeroElementos;
    int tamanhoTabela;
    FuncaoHash* funcaoHash;
    list<Associacao<T>> tabela[tamanho];
};

template<int tamanho, typename T>
void cria(Dicionario<tamanho, T>& dicionario, FuncaoHash* f)
{
    dicionario.numeroElementos = 0;
    dicionario.tamanhoTabela = tamanho;
    dicionario.funcaoHash = f;
};

template<int tamanho, typename T>
void destroi(Dicionario<tamanho, T>& dicionario)
{
    for (int i = 0; i < dicionario.tamanhoTabela; i++)
        dicionario.tabela[i].clear();
    dicionario.numeroElementos = 0;
};

template<int tamanho, typename T>
int numeroDeElementos(Dicionario<tamanho, T> dicionario)
{
    return dicionario.numeroElementos;
}

template<int tamanho, typename T>
bool ehVAzio(Dicionario<tamanho, T> dicionario)
{
    return dicionario.numeroElementos == 0;
}

template<int tamanho, typename T>
int posicao(Dicionario<tamanho, T> dicionario, int chave)
{
    return dicionario.funcaoHash(chave);
}

template<int tamanho, typename T>
bool existeElemento(Dicionario<tamanho, T> dicionario, int chave)
{
    for (auto it = dicionario.tabela[dicionario.funcaoHash(chave)].begin();
        it != dicionario.tabela[dicionario.funcaoHash(chave)].end(); ++it)
        if (pegaChave(*it) == chave) return true;
    return false;
}

template<int tamanho, typename T>
void insere(Dicionario<tamanho, T>& dicionario, int chave, T informacao)
{
    Associacao<T> associacao = cria(chave, informacao);
    dicionario.tabela[(dicionario.funcaoHash(chave))].push_back(associacao);
    dicionario.numeroElementos++;
}

template<int tamanho, typename T>
void retira(Dicionario<tamanho, T>& dicionario, int chave)
{
    for (auto it = dicionario.tabela[dicionario.funcaoHash(chave)].begin();
        it != dicionario.tabela[dicionario.funcaoHash(chave)].end(); ++it)
        if (pegaChave(*it) == chave)
        {
            dicionario.tabela[dicionario.funcaoHash(chave)].erase(it);
            break;
        }
    dicionario.numeroElementos--;
}

template<int tamanho, typename T>
void mostra(Dicionario<tamanho, T> dicionario)
{
    for (int i = 0; i < dicionario.tamanhoTabela; i++)
        if (!dicionario.tabela[i].empty())
        {
            cout << i << " -> ";
            for (auto it = dicionario.tabela[i].begin(); it != dicionario.tabela[i].
                end(); ++it)
                cout << pegaChave((*it)) << " " << pegaInformacao((*it)) << " ";
            cout << endl;
        }
}

#endif // DICIONARIO_H_INCLUDED
