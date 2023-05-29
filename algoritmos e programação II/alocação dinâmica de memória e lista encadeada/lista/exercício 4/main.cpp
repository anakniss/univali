#include <iostream>

using namespace std;

//Escreva um procedimento que elimine a primeira ocorrência de um determinado valor de uma lista de
//valores inteiros.

typedef struct Nodo{
    int elemento;
    struct Nodo *proximo;
}Lista;

Lista* montaLista();
void exibaLista(Lista *);
void excluiElemento(Lista **, int);

int main()
{
    Lista *head = montaLista();
    exibaLista(head);
    excluiElemento(&head, 60);
    exibaLista(head);

}

Lista* montaLista(){
    Lista* atual, *paux, *lista = NULL;
    char opcao;

    do {
        atual = new Lista;

        cout << "Informe o numero:" << endl;
        cin >> atual->elemento ;

        cin.ignore();

        if(lista == NULL){
            lista = atual;
            paux = atual;
        }
        else {
            paux->proximo = atual;
            paux = atual;
        }
        cout << "Deseja adicionar outro elemento na lista? S/N" << endl;
        opcao = toupper(cin.get());

        cin.ignore();

    } while(opcao != 'N');

    atual->proximo = NULL;

    return lista;
}

void exibaLista(Lista *lista){
    Lista *atual = lista;
    while(atual != NULL){
        cout << "Numero: " << atual->elemento << endl;
        cout << "==========================" << endl;

        atual = atual->proximo;
    }
}

void excluiElemento(Lista **head, int elemento){
    Lista *atual, *ant = NULL;
    atual = *head;

    if(atual != NULL){
        if(atual->elemento == elemento){
            *head = atual->proximo;
            delete atual;
            return;
        }
        ant = *head;
        atual = atual->proximo;
        while(atual != NULL and atual->elemento != elemento){
            ant = atual;
            atual = atual->proximo;
        }
        if(atual != NULL){
            ant->proximo = atual->proximo;
            delete atual;
        }
    }
}
