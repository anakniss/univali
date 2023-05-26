#include <iostream>

using namespace std;

//Suponha a existência de uma lista encadeada com as matrículas de um conjunto de funcionários.
//Admita também que exista outra lista encadeada onde cada nodo contenha matrícula do funcionário e
//nome do seu dependente. Faça um procedimento que escreva, para cada funcionário, o nome do
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
        cout << "Sem memória";
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
