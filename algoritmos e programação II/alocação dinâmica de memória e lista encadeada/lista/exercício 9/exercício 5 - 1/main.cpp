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

void insereFinal(FuncLista **, string);
void destroiLista(FuncLista **);
void exibeLista(FuncLista *);

int main()
{
    FuncLista* listaFunc = NULL;
    DepLista* depLista = NULL;
    string matricula;

    do{
        cout <<"Informe a matricula ou -1 para sair: " << endl;
        getline(cin, matricula);
        if(matricula != "-1")
            insereFinal(&listaFunc, matricula);
    }while(matricula != "-1");

    exibeLista(listaFunc);
}

void insereFinal(FuncLista **ptr_lista, string elemento){
    FuncLista *p, *pant;
    p = new FuncLista;
    cout << p << endl;
    if(p == NULL){
        cout << "Sem mem�ria";
        cin.get();
        exit(1);
    }

    p->matricula = elemento;
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

void destroiLista(FuncLista **ptr_lista) {
    FuncLista *p;
    while(*ptr_lista != NULL){
        p = *ptr_lista;
        *ptr_lista = (*ptr_lista)->proximo;
        delete p;
    }
}

void exibeLista(FuncLista *p){
    while(p != NULL){
        cout << "Endereco(Nodo): " << p << endl;
        cout << "Valor: " << p->matricula << endl;
        p = p->proximo;
    }
}

FuncLista* retornaEndereco(FuncLista *p, string elemento){
    if(p == NULL)
        return NULL;
    while(p != NULL and p->matricula != elemento){
        p = p->proximo;
    }
    return p;
}
