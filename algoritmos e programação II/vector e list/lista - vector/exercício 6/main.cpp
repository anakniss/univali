#include <iostream>
#include <vector>
#include <algorithm>

/*Escreva uma função vector<int> merge_sorted(vector<int> a,
vector<int> b) que intercala dois arrays ordenados, produzindo um novo array
ordenado. Mantenha um índice para cada array, indicando quanto dele já foi processado.
A cada vez, acrescente o menor elemento não processado de qualquer um dos arrays,
então avance o índice.
P.ex., a é 1,4,9,16 e b é 4,7,9,9,11 então merge_sorted retorna o array
1,4,4,7,9,9,9,11,16 */

using namespace std;

void adicionaVetores(string, vector<int> &);
vector<int> merge_sorted(vector<int> , vector<int>);

int main()
{
    vector<int> a;
    vector<int> b;
    vector<int> c;

    adicionaVetores("Informe um valor a ser adicionado no vetor A: ", a);
    sort(a.begin(), a.end());

    adicionaVetores("Informe um valor a ser adicionado no vetor B: ", b);
    sort(b.begin(), b.end());

    c  = merge_sorted(a, b);

    cout << "VETOR COMBINADO E ORDENADO" << endl;

    for(int i=0; i<c.size(); i++)
    {
        cout << c[i] << endl;
    }
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

vector<int> merge_sorted(vector<int> a, vector<int> b)
{
    vector<int> c;
    int iA = 0, iB = 0;

    for(int i=0; i < a.size() + b.size(); i++)
    {
        if(iA >= a.size())
        {
            c.push_back(b[iB]);
            iB++;
        }

        else if(iB >= b.size())
        {
            c.push_back(a[iA]);
            iA++;
        }

        else if(a[iA] < b[iB])
        {
            c.push_back(a[iA]);
            iA++;
        }
        else
        {
            c.push_back(b[iB]);
            iB++;
        }
    }

    return c;
}
