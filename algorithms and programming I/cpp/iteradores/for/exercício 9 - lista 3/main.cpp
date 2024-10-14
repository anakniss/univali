#include <iostream>

using namespace std;

int main()
{
    int i, soma = 0;

    for(i = 1; i <= 100; i++){
        soma = soma + i;
    }
    cout << "Soma dos termos: " << soma << endl;
}
