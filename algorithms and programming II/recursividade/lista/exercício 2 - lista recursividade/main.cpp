#include <iostream>

using namespace std;

int calculaNaturais(int n){
    if(n == 0){
        return 0;
    }
    return n + calculaNaturais(n - 1);
}

int informaValor(){
    int n;
    cout << "Informe o número a ser somado: " << endl;
    cin >> n;
    return n;
}

void mostraValor(int n){
    cout << "Soma: " << n << endl;
}

int main()
{
    int n = informaValor();
    int r = calculaNaturais(n);
    mostraValor(r);
}
