#include <iostream>
#define TMAX 15

using namespace std;


int main()
{
    int n, i;
    float prod = 0, mult;
    float v[TMAX];
    float w[TMAX];

    do {
        cout << "Informe a quantidade de valores dos dois vetores: ";
        cin >> n;
    } while(n < 0 or n > 15);

    for(i=0; i<n; i++){
        cout << "Informe o valor do vetor V: " << endl;
        cin >> v[i];
    }

    for(i=0; i<n; i++){
        cout << "Informe o valor do vetor W: " << endl;
        cin >> w[i];

        if(w[i] == 0){
            cout << "O número precisa ser diferente de 0. Tente novamente: " << endl;
            cin >> w[i];
        }
    }

    for(i=0; i<n; i++){
        cout << "Soma " << i+1 << ": " << v[i] + w[i] << endl;
        cout << "Subtração " << i+1 << ": " << v[i] - w[i] << endl;
        cout << "Divisão " << i+1 << ": " << v[i] / w[i] << endl;

        mult = v[i] * w[i];
        cout << "Multiplicação " << i+1 << ": " << mult << endl;

        prod += mult;
    }

    cout << "Produto escalar: " << prod;

    if(prod == 0){
        cout << "Vetores ORTOGONAIS";
    }
}
