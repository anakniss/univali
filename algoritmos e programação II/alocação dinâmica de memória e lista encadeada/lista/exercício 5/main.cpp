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
        cout << "Sem memória";
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
