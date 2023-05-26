#include <iostream>

using namespace std;

//Suponha a exist�ncia de uma lista encadeada com as matr�culas de um conjunto de funcion�rios.
//Admita tamb�m que exista outra lista encadeada onde cada nodo contenha matr�cula do funcion�rio e
//nome do seu dependente. Fa�a um procedimento que escreva, para cada funcion�rio, o nome do
//seu(s) dependente(s).

typedef struct Nodo {
    string matricula;
    struct Nodo *proximo;
} FuncLista;

typedef struct Nodo2 {
    string matricula;
    string nome;
    struct Nodo2 *proximo;
} DepLista;

int main()
{
    FuncLista* listaFunc = new FuncLista;
    DepLista* depLista = new DepLista;

    inserenofinal(listaFunc, string nome);
    exibelista(listaFunc);
}

void inserenofinal(FuncLista **ptr_lista, string matricula){
    FuncLista *p, *pant;
    p = new FuncLista;

    if(p == NULL){
        cout << "Sem mem�ria";
        cin.get();
        exit(1);
    }

    p->valor = valor;
    p->proximo = NULL;

    if(*ptr_lista == NULL) {
        *ptr_lista = p;
        return;
    }

    pant = *ptr_lista;
    while(pant->proximo != NULL) {
        pant = pant->proximo;
    }

    pant->proximo = p;
}

void destroilista(FuncLista **ptr_lista) {
    FuncLista *p;
    while(*ptr_lista != NULL){
        p = *ptr_lista;
        *ptr_lista = (*ptr_lista)->proximo;
        delete p;
    }
}

void exibelista(FuncLista *lista){
    FuncLista *p = lista;
    while(p != NULL){
        cout << "\n Nodo "<< p << " Valor " << p->valor << endl;
        p = p->proximo;
    }
}

FuncLista* retornaEndereco(FuncLista *p, string elemento){
    if(p == NULL)
        return NULL;
    while(p != NULL and p->nome != elemento){
        p = p->proximo;
    }
    return p;
}
