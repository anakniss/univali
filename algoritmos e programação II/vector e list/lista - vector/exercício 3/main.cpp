#include <iostream>
#include <vector>

using namespace std;

//Escreva um procedimento reverse que inverte a sequência dos elementos em um
//vetor.

void inverte(vector<int>&);

int main()
{
    vector<int> meuVetor;

    meuVetor.push_back(1);
    meuVetor.push_back(2);
    meuVetor.push_back(3);
    meuVetor.push_back(4);

    for(int i=0; i<meuVetor.size(); i++){
        cout << meuVetor[i] << endl;
    }

    inverte(meuVetor);

    for(int i=0; i<meuVetor.size(); i++){
        cout << meuVetor[i] << endl;
    }
}

void inverte(vector<int> &a){
    int n = a.size() - 1;
    int j = 0;
    for(int i=0, j = n - i; i<n / 2; i++, j--){
        swap(a[i], a[j]);
    }
}
