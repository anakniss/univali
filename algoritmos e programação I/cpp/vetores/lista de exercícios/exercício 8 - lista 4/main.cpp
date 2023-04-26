#include <iostream>
#define TMAX 15

using namespace std;

int main()
{
    int v[TMAX];
    int i, n, maior = 0;

    cout << "Informe o número de valores a serem ordenados: " << endl;
    cin >> n;

    while(n < 0 or n > 15){
        cout << "Valor inválido. Informe novamente: " << endl;
        cin >> n;
    }

    for(i=0; i<n; i++){
        cout << "Informe o valor: " << endl;
        cin >> v[i];
    }

    int y = n;

    for(i=0; i<y; i++){
        for(i=0; i<y; i++){
            if(v[i] > maior){
                maior = v[i];
            }
        }
        v[y-1] = maior;
        cout <<  "Maior: " << v[n-1] << endl;
        y = y-1;
    }

    cout << "Valor de N: " << v[y] << endl;

    for(i=0; i<n; i++){
        cout << v[i] << " ";
    }
}
