#include <iostream>
#include <vector>

using namespace std;

double scalar_product(vector<double>, vector<double>);

int main()
{
    vector<double> meuVetor;
    vector<double> meuVetor2;

    meuVetor.push_back(70);
    meuVetor.push_back(50);
    meuVetor.push_back(20);

    meuVetor2.push_back(5);
    meuVetor2.push_back(4);
    meuVetor2.push_back(3);

    double result = scalar_product(meuVetor, meuVetor2);

    if(result != -1){
        cout << "Soma: " << result << endl;
    }
    else
        cout << "Tamanho invalido" << endl;

}

double scalar_product(vector<double> a, vector<double> b){
    vector<double> ::iterator j;
    vector<double> ::iterator k;
    float soma = 0;
    if(a.size() == b.size()){
        for(j = a.begin(), k = b.begin(); j != a.end(); j++, k++){
            soma += *j * *k;

        }
        return soma;
    }
    return -1;
}
