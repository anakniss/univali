#include <iostream>
#define TMAX 5

using namespace std;

//Construa um procedimento recursivo para verificar
//a existência de determinado valor y em um vetor X
//de n(1 <= n <= 10) elementos inteiros.

bool pesquisaValor(int n, int chave, int v[]){
    if(chave == v[n]){
        return true;
    }
    if(n == 0){
        return false;
    }
    return pesquisaValor(n-1, chave, v);
}

int main()
{
    int v[TMAX] = {1, 4, 8, 10, 3};
    int chave = 10;
    int n = 5;

    cout << pesquisaValor(n-1, chave, v);
}
