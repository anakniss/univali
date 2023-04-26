#include <iostream>
#define TMAX 15

using namespace std;

int main()
{
    int v[TMAX];
    int i, j, n, maior = 0;

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


    for(i=0; i < n-1; i++){
        for(j=0; j < n-i-1; i++){
            if(v[i] > v[i + 1]){
                int aux = v[i+1];
                v[i+1] = v[i];
                v[i] = aux;
            }
        }
    }

    for(i=0; i<n; i++){
        cout << v[i] << " ";
    }
}
