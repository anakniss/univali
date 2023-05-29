#include <iostream>

using namespace std;

typedef struct Nodo {
    int n;
    Nodo *prox;
} Lista;

void exibeValores(Nodo *r) {
    do {
       cout << "Valor: " << r->n << endl;
       r = r->prox;
    }
    while (r != nullptr);
}

void deletaLista(Nodo* r) {
   Nodo *aux;
   do {
       aux = r->prox;
       delete r;
       r = aux;
   }
   while (r != nullptr);
}

void excluiNumero(Nodo* r, int n) {
    Nodo* ant = nullptr;
    do {
       if (r->n == n) {
           if (ant == nullptr) {
               delete r;
               r = nullptr;
           }
           else {
               ant->prox = r->prox;
               delete r;
               r = ant->prox;
           }
       }
       else {
           ant = r;
           r = r->prox;
       }
    }
    while (r != nullptr);
}

void adicionaNumero(Nodo **r, int v){
    Nodo *novo = new Nodo;

    novo->n = v;
    novo->prox = nullptr;
    r->prox = novo;

    while (r->prox != nullptr){
        r = r->prox;
    }
}

void consulta(Nodo *r, int chave){
    do {
        if(r->n == chave){
            cout << "Valor encontrado no seguinte endereco: " << r->prox << endl;
            return;
        }
        r = r->prox;
    } while(r->prox != nullptr);

    cout << "Valor não encontrado" << endl;
}

int main()
{
    Nodo *n1 = nullptr;

    adicionaNumero(n1, 12);
    adicionaNumero(n1, 16);
    adicionaNumero(n1, 17);
    exibeValores(n1);
    consulta(n1, 16);
    consulta(n1, 12);
    consulta(n1, 3);
}
