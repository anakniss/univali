#include <iostream>

using namespace std;

int main()
{
    char opcao = 'S';
    int num;
    int i = 1;
    int qntdDiv = 0;

    while(opcao == 'S') {

        cout << "Informe um número inteiro" << endl;
        cin >> num;

        while (num >= i){
            if (num % i == 0){
                cout << "Número divisível: " << i << endl;
                qntdDiv++;
            }
            i++;
        }

        cout << "A quantidade de divisores que o número " << num << " possui é de: " << qntdDiv << endl;

        i = 1;
        qntdDiv = 0;

        cout << "Gostaria de verificar mais um número? S/N" << endl;
        cin >> opcao;
    }
}
