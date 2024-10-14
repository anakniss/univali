#include <iostream>

using namespace std;

int main()
{
    int n, i, fib = 1, aux = 0, result = 0;
    char opcao;

     do {

        cout << "Informe o valor de vezes que você gostaria de calcular termos de Fibonacci: " << endl;
        cin >> n;

        if (n < 2){
            cout << "Informe um valor igual ou maior que 2" << endl;
        }

     } while(n < 2);

     for(i=0; i < n; i++){
        result = fib + aux;
        aux = fib;
        fib = result;
        cout << "Resultado: " << result << endl;
     }
}
