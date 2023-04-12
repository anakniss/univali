#include <iostream>

using namespace std;

int main()
{
    float num = 1, den = 2, soma = 0, div;
    int i, j = 0, aux = 4;

    for(i = 1; i <= 20; i++){
        num = num + 2;
        div = num / den;
        soma = soma + div;
        cout << soma << endl;
        den = den + aux;
        aux += 2;
    }
}
