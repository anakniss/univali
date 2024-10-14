#include <iostream>

using namespace std;

int main()
{
    float div, soma = 0;
    int i;

    for (i = 1; i <= 100; i++){
        div = 1.0 / i;
        soma += div;
    }

    cout << "Soma: " << soma << endl;
}
