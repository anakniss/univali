#include <iostream>
#define TMAX 10

using namespace std;

int main()
{
    int n, i;
    int x[TMAX];

    do {
        cout << "Informe a quantidade de valores a serem lidos: ";
        cin >> n;
    } while(n < 1 or n > 10);

    for(i=0; i<n; i++){
        cout << "Informe o valor: " << endl;
        cin >> x[i];
    }

    int y = n - 1;
    int a, b;

    for(i=0; i < n/2; i++){
        a = x[y];
        x[y] = x[i];
        x[i] = a;

        y--;
    }

    cout << "Vetor final: " << endl;
    for(i=0; i<n; i++){
        cout << x[i];
    }
}
