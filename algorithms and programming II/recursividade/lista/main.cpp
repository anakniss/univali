#include <iostream>

using namespace std;

int calculaFibonacci(int n){
    if(n == 1 or n==2){
        return 1;
    }

    return calculaFibonacci(n-1) + calculaFibonacci(n-2);
}

int informaValor(){
    int n;
    cout << "Informe a posição que deseja verificar: " << endl;
    cin >> n;
    return n;
}

void mostraValor(int n){
    cout << "Valor: " << n;
}

int main() {
    int n = informaValor();
    int r = calculaFibonacci(n);
    mostraValor(r);
}
