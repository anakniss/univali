#include <iostream>
#define TMAX 3000

using namespace std;

int main()
{
    int n, i, pp;
    int p[TMAX];
    float s[TMAX];
    float renda;

    cout << "Informe a quantidade de turistas (mínimo 1 e máximo 3000): " << endl;
    cin >> n;

    while(n < 1 or n > 3000) {
        cout << "A informação não condiz com os requisitos. Favor informar uma nova quantidade" << endl;
        cin >> n;
    }

    for(i=0; i<n; i++){
        p[i] = 0;
    }

    for(i=0; i<n; i++){
        s[i] = 0;
    }

    for(i=0; i < n; i++){
        cout << "Informe o código da praia preferida (1 a 42): " << endl;
        cin >> pp;

        while(pp < 1 or pp > 42) {
            cout << "A informação não condiz com os requisitos. Favor informar um novo código de 1 a 42" << endl;
            cin >> pp;
        }

        cout << "Informe a renda mensal: " << endl;
        cin >> renda;

        p[pp - 1]++;
        s[pp - 1] += renda;
    }

    for(i=0; i<42; i++){
        cout << "A quantidade de turistas que preferem a praia "  << i+1 << " eh de: " << p[i] << endl;

        if(p[i] != 0){
            s[i] = s[i] / p[i];
        }
        else {
            s[i] = 0;
        }

        cout << "A renda média da praia " << p[i] << " eh de " << s[i] << endl;
    }


}
