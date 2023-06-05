#include <iostream>
#include <vector>

using namespace std;


//Escreva uma função vector<int> append(vector<int> a, vector<int> b)
//que acrescenta um vetor após outro.
//Ex: vetor 1,4,9,16 e b 9,7,4,9,11 então append retorna o vetor 1,4,9,16,9,7,4,9,11

vector<int> append(vector<int>, vector<int>);
void adicionaVetores(string, vector<int> &);

int main()
{
    vector<int> a;
    vector<int> b;
    vector<int> c;

    adicionaVetores("Informe um valor a ser adicionado no vetor A: ", a);
    adicionaVetores("Informe um valor a ser adicionado no vetor B: ", b);

    c = append(a, b);

    for(int i=0; i<c.size() - 1; i++){
        cout << c[i] << ", ";
    }

    cout << c.back() << ".";
}

void adicionaVetores(string mensagem, vector<int> &meuVetor){
    char opcao;
    int n;
    do {
        cout << mensagem << endl;
        cin >> n;
        meuVetor.push_back(n);
        cin.ignore();

        cout << "Outro? S/N" << endl;
        opcao = toupper(cin.get());
    } while(opcao != 'N');
}

vector<int> append(vector<int> a, vector<int> b){
    vector<int> c;

    for(int i=0; i<a.size(); i++){
        c.push_back(a[i]);
    }

    for(int i=0; i< b.size(); i++){
        c.push_back(b[i]);
    }

    return c;
}
