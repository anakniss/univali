#include <iostream>
#include <vector>

using namespace std;

/*P9.7. Escreva uma função predicado bool equals(vector<int> a, vector<int>
b) que verifica se dois vetores têm os mesmos elementos na mesma ordem. */

bool equals(vector<int>, vector<int>);
void adicionaVetores(string, vector<int> &);

int main()
{
    vector<int> a;
    vector<int> b;

    adicionaVetores("Informe um valor a ser adicionado no vetor A: ", a);
    adicionaVetores("Informe um valor a ser adicionado no vetor B: ", b);

    bool verifica = equals(a, b);

    if(verifica != true)
    {
        cout << "Os vetores NAO possuem os mesmos elementos na mesma ordem";
    }
    else
    {
        cout << "Os vetores possuem os mesmos elementos na mesma ordem";
    }

    return 0;
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

bool equals(vector<int> a, vector<int> b)
{
    if(a.size() != b.size())
    {
        return false;
    }

    //Como a e b possuem o mesmo tamanho, é indiferente escolher qualquer um dos dois.
    for(int i=0; i<a.size(); i++)
    {
        if(a[i] != b[i])
        {
            return false;
        }
    }

    return true;
}
