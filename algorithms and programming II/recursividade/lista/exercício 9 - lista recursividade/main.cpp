#include <iostream>
#define TMAX 10

// Escreva uma função recursiva para verificar se dois vetores X e Y de n (1 <= n <= 10) elementos inteiros são iguais, ou seja, Xi = Yi.

using namespace std;

bool comparaVetores(int n, int a[], int b[]){
    if(n == -1){
        return true;
    }
    if(a[n] == b[n]){
        return comparaVetores(n-1, a, b);
    }

    return false;
}

int main()
{
    int n = 5;
    int a[TMAX] = {1, 2, 3, 4, 5};
    int b[TMAX] = {1, 2, 3, 4, 5};

    cout << comparaVetores(n-1, a, b);
}
