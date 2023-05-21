#include <iostream>

using namespace std;

int numeros[10];

int valor = 1;
int divisores = 0;
int numero, i;

int main()
{
    for(i = 0; i < 10; i++){
        cout << "Digite o número: " << endl;
        cin >> numero;

        numeros[i] = numero;

        divisores = 0;
        valor = 1;

        if(numero > 0) {
            while(valor <= numero){
                if(numero % valor == 0){
                    divisores++;
                }
                valor++;
            }
            if(divisores == 2){
                cout << "O número " << numero << " é primo!" << endl;
            }
            else {
                cout << "O número " << numero << " NÃO é primo!" << endl;
            }
        }

        else {
            cout << "Valor negativo ou igual a zero!";
        }
    }
}
