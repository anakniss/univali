#include <iostream>

using namespace std;

long polinomioRec(int x, int n, int vetA[]){
    if(n == 0)
        return vet[0];
    return vetA[n] * pow(x, n) + polinomioRec(x, n-1, vetA);
}

int main()
{
    int n = 4;

    for (int i=n; i >= 0; i--){
        cout << "Informe o valor da posição: " << i-1;
        cin >> vetA[i];
    }
    cout << polinomioRec();
}
