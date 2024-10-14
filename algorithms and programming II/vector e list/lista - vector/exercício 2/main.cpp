#include <iostream>
#include <vector>

using namespace std;

//Escreva uma função que calcule a soma alternada de todos os elementos em um vetor.
//P.ex. vetor 1,4,9,16,9,7,4,9,11 calcula 1 - 4 + 9 - 16 + 9 - 7 + 4 - 9 + 11 = -2

int somaAlternada(vector<int>);

int main()
{
    vector<int> meuVetor;

    meuVetor.push_back(70);
    meuVetor.push_back(40);
    meuVetor.push_back(10);
    meuVetor.push_back(80);

    int result = somaAlternada(meuVetor);

    cout << "Soma alternada: " << result;
}

int somaAlternada(vector<int> a){
    int soma = 0;
    for(int i = 0; i<a.size(); i++){
        if(i%2 == 0)
            soma += a[i];
        else
            soma -= a[i];
    }
    return soma;
}
