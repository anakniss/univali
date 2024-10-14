#include <iostream>

using namespace std;
#define TMAX 10

int main(){

    int n, i;

    float v[TMAX];
    float s[TMAX];

    do {
        cout << "Informe a quantidade de valores (mínimo 3 e máximo 10): " << endl;
        cin >> n;

    } while(n < 3 or n > 10);

    for(i=0; i<n; i++){
        cout << "Informe um valor: " << endl;
        cin >> v[i];
    }

    cout << "Valores observados/iniciais: ";
    for(i=0; i<n; i++){
        cout << v[i] << " ";
    }

    s[0] = v[0];
    s[n-1] = v[n-1];

    for(i=1; i < n-1; i++){
        s[i] = (v[i-1] + v[i] + v[i+1]) / 3;
    }

    cout << endl << "Valores suavizados: ";
    for(i=0; i<n; i++){
        cout << s[i] << " ";
    }
}
