#include <iostream>

using namespace std;

//Considerando nome e peso de um número qualquer de pessoas, elabore funções e procedimentos para:
//i) armazenar em uma estrutura de lista encadeada essas informações;
//ii) calcular e escrever o peso médio;
//iii) escrever o nome das pessoas com peso inferior a 50kg
//iv) verificar se uma determinada pessoa está representada na lista.

typedef struct Nodo{
    string nome;
    float peso;
    struct Nodo *proximo;
} Lista;

Nodo* procuraElemento(Nodo* head, string elemento){
    Nodo* atual = head;
    while(atual != nullptr){
        if(atual->nome == elemento){
            return atual;
        }
        atual = atual->proximo;
    }
    return nullptr;
}

void excluiNodo(Nodo **head, string elemento){
    //procuraElemento(*head)
}

int main()
{
    Nodo* head = new Nodo;
    Nodo head2 = *head;
    Nodo* primeiro = new Nodo;
    Nodo* segundo = new Nodo;

    head->nome = "Bianca";
    head->peso = 49,7;
    head->proximo = primeiro;

    primeiro->nome = "Lucas";
    primeiro->peso = 69,5;
    primeiro->proximo = segundo;

    segundo->nome = "Matheus";
    segundo->peso = 60;
    segundo->proximo = nullptr;
}
