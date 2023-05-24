#include <iostream>

using namespace std;

typedef struct Nodo {
    string elemento;
    struct Nodo *proximo;
} Lista;

void insereAposNumero(Lista* lauxl, int n, string elem){
    while(laux != NULL){
        if(laux->valor == n){
            Lista * nodoe = new Lista;
            nodoe->valor = elem;
            nodoe-> laux->prox;
            laux->prox = nodoe;
            return;
        }
        laux = laux->prox;
    }
}

int main()
{
    Lista *head = new Lista;

}
