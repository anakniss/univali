#include <iostream>

using namespace std;

int main()
{
    char opcao = 'S';
    int num;
    int i = 1;
    int qntdDiv = 0;

    while(opcao == 'S') {

        cout << "Informe um n�mero inteiro" << endl;
        cin >> num;

        while (num >= i){
            if (num % i == 0){
                cout << "N�mero divis�vel: " << i << endl;
                qntdDiv++;
            }
            i++;
        }

        cout << "A quantidade de divisores que o n�mero " << num << " possui � de: " << qntdDiv << endl;

        i = 1;
        qntdDiv = 0;

        cout << "Gostaria de verificar mais um n�mero? S/N" << endl;
        cin >> opcao;
    }
}
