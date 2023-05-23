#include <iostream>

//Faça uma função que retorne o endereço de um elemento qualquer em uma lista encadeada de
//strings. Caso o elemento não esteja na lista, a função deverá retornar nulo.

using namespace std;

typedef struct Nodo {
    string dado;
    struct Nodo *proximo;
} Lista;

Nodo* procuraElemento(Nodo* head, string elemento){
    Nodo* atual = head;
    while(atual != nullptr){
        if(atual->dado == elemento){
            return atual;
        }
        atual = atual->proximo;
    }
    return nullptr;
}

string leiaElemento(){
    string dado;

    cout << "Informe o elemento a ser comparado: " << endl;
    getline(cin, dado);

    return dado;
}

int main()
{
    Nodo *head = new Nodo;
    Nodo *primeiro = new Nodo;
    Nodo *segundo = new Nodo;

    head->dado = "Ana";
    head->proximo = primeiro;
    cout << "Valor do head: " << head << endl;

    primeiro->dado = "Kniss";
    primeiro->proximo = segundo;

    segundo->dado = "Oie";
    segundo->proximo = nullptr;

    string elemento = leiaElemento();
    Nodo* result = procuraElemento(head, elemento);
    cout << "Valor de result: " << result << endl;

    if(result != nullptr){
        cout << "Endereco identificado: " << result << endl;
    }
    else {
        cout << "Endereco nao encontrado" << endl;
    }

    delete head;
    delete primeiro;
    delete segundo;
}
