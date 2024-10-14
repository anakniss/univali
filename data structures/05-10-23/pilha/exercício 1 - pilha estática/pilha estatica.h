#ifndef PILHA_ESTATICA_H_INCLUDED
#define PILHA_ESTATICA_H_INCLUDED

template<typename T, int MAX>
struct PilhaEstatica{
    int cima;
    int baixo;
    int cardinalidade;
    T elementos[MAX];
};

template<typename T, int MAX>
bool ehVazia(PilhaEstatica<T, MAX> pilha){
    return pilha.cardinalidade == 0;
}

template<typename T, int MAX>
void cria(PilhaEstatica<T, MAX> pilha){
    pilha.cardinalidade = 0;
    pilha.cima = 0;
    pilha.baixo = 0;
}

template<typename T, int MAX>
void ehVazia(PilhaEstatica<T, MAX> pilha){
    return pilha.cardinalidade == 0;
}

template<typename T, int MAX>
bool temEspaco(PilhaEstatica<T, MAX> pilha){
    return pilha.cardinalidade < MAX;
}

template<typename T, int MAX>
bool existeElemento(PilhaEstatica<T, MAX> pilha){

}


#endif // PILHA_ESTATICA_H_INCLUDED
