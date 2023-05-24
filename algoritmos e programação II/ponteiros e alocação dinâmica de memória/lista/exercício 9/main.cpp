#include <iostream>

using namespace std;

//Escreva uma função que verifique se duas listas encadeadas em memória são iguais.

typedef struct Nodo {
    int dado;
    struct Nodo *proximo;
} Lista;

bool verificaIgualdade(Lista *l1, Lista *l2){
    while (l1 != NULL and l2 != NULL){
        if(l1->valor != l2->valor)
            return false;
        l1 = l1->prox;
        l2 = l2->prox;
    }
    if(l1 == NULL and l2 == NULL){
        return true;
    }
    return false;
}

int main()
{

}
