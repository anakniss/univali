#include <iostream>

using namespace std;

typedef struct Nodo {
    int n;
    Nodo *prox;
} Lista;

void exibeValores(Nodo *r) {
    do {
       cout << r->n;
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

void adicionaNumero(Nodo *r, int v){
    Nodo *novo = new Nodo;

    cout << "Anterior: " << r->prox << endl;

    r->prox = novo;
    novo->n = v;
    novo->prox = nullptr;

    cout << novo->n << endl;
    cout << "Atual: " << r->prox << endl;
}

int main()
{
    Nodo *n1 = new Nodo;
    n1->n = 1;
    n1->prox = nullptr;

    adicionaNumero(n1, 2);
    cout << "Depois da funcao: " << n1->prox << endl;

    cout << n1->n;
}
