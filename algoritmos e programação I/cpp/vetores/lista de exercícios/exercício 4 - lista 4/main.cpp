#include <iostream>
#define TMAX 15

using namespace std;

int main()
{
    int v[TMAX];
    int n;

    do {
        cout << "Informe a quantidade de elementos a serem comparados: " << endl;
        cin >> n;
    } while(n<0 or n>15);

    for(int i=0; i<n; i++){
        cout << "Informe o valor: " << endl;
        cin >> v[i];
    }

    int maior = v[0];
    int menor = v[0];

    for(int i=1; i<n; i++){
        if(v[i] > maior){
            maior = v[i];
        }
        else if(v[i] < menor){
            menor = v[i];
        }
    }
    cout << "Valor maior: " << maior << endl;
    cout << "Valor menor: " << menor << endl;
}
