#ifndef ASSOCIACOES_H_INCLUDED
#define ASSOCIACOES_H_INCLUDED

template<typename T>
struct Associacao
{
    int chave;
    T informacao;
};

template<typename T>
Associacao<T> cria(int chave, T informacao)
{
    Associacao<T> associacao;
    associacao.chave = chave;
    associacao.informacao = informacao;
    return associacao;
}

template<typename T>
int pegaChave(Associacao<T> associacao)
{
    return associacao.chave;
}

template<typename T>
T pegaInformacao(Associacao<T> associacao)
{
    return associacao.informacao;
}

#endif // ASSOCIACOES_H_INCLUDED
#pragma once
