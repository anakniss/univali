#include <iostream>

using namespace std;

//Escreva um procedimento que insira um novo elemento em uma lista de valores inteiros, após a
//primeira ocorrência do valor 80, caso exista este valor.

typedef struct Nodo {
    int elemento;
    struct Nodo *proximo;
} Lista;

Lista* montaLista();
void insereAposNumero(Lista*, int, int);
void exibaLista(Lista *);

int main()
{
    Lista *head = montaLista();
    insereAposNumero(head, 80, 90);
    exibaLista(head);
}

Lista* montaLista(){
    Lista* atual, *paux, *lista = NULL;
    char opcao;

    do {
        atual = new Lista;

        cout << "Informe o numero: " << endl;
        cin >> atual->elemento;

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

void insereAposNumero(Lista* head, int n, int elem){
    while(head != NULL){
        if(head->elemento == n){
            Lista *novo = new Lista;
            novo->elemento = elem;
            novo->proximo = head->proximo;
            head->proximo = novo;
            return;
        }
      head = head->proximo;
    }
}

void exibaLista(Lista *lista){
    Lista *atual = lista;
    while(atual != NULL){
        cout << "Numero: " << atual->elemento << endl;
        cout << "====================" << endl;

        atual = atual->proximo;
    }
}
