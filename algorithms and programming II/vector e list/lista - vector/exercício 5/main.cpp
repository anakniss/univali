#include <iostream>
#include <vector>

using namespace std;

//Escreva uma função vector<int> merge(vector<int> a, vector<int> b)
//que intercala dois arrays, alternando elementos dos dois arrays. Se um array é mais
//curto do que o outro, então alterne enquanto você puder e depois acrescente os elementos
//restantes do array mais longo.

vector<int> merge(vector<int> , vector<int>);
void adicionaVetores(string mensagem, vector<int> &);

int main()
{
    vector<int> a;
    vector<int> b;
    vector<int> c;

    adicionaVetores("Informe um valor a ser adicionado no vetor A: ", a);
    adicionaVetores("Informe um valor a ser adicionado no vetor B: ", b);

    c = merge(a, b);

    cout << "SEQUENCIA DOS VETORES" << endl;

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

vector<int> merge(vector<int> a, vector<int> b){
    int i, menor;
    vector<int> c;
    if(a.size() < b.size()){
        menor = a.size();
    }
    else{
        menor = b.size();
    }
    for(i=0; i<menor; i++){
        c.push_back(a[i]);
        c.push_back(b[i]);
    }

    if(b.size() > a.size()){
        for(; i<b.size(); i++){
            c.push_back(b[i]);
            cout << "Valor de B: " << endl;
        }
    }
    else {
        for(; i<a.size(); i++){
            c.push_back(a[i]);
            cout << "Valor de A: " << endl;
        }
    }

    return c;
}
