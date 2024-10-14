#include <iostream>

using namespace std;

int main()
{
    int i, j, n, m, aux = 1, soma = 0;

    cout << "Informe a quantidade de valores a serem lidos por M: " << endl;
    cin >> n;


    for(i = 0; i < n; i++){

        cout << "Informe o valor de M: " << endl;
        cin >> m;

        if(m < 0) {
            cout << "Valor inválido" << endl;
        }
        else {
            cout << "Valor lido: " << m << endl;
            for(j = 1; j <= m; j++){
                soma += j;
            }
            cout << "Soma: " << soma << endl;

            soma = 0;
        }
    }
}
