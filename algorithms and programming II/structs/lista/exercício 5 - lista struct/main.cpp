#include <iostream>

using namespace std;

typedef struct {
    int codigo;
    string nomeProfissao;
} Profissao;

int leiaQuantidade(){
    int n;
    cout << "Informe a quantidade de profissoes a serem lidas: " << endl;
    cin >> n;

    return n;
}

char leiaCaracter(){
    char opcao;
    do {
        cout << "Outro? S/N" << endl;
        cin.ignore();
        opcao = toupper(cin.get());
    } while(opcao != 'S' and opcao != 'N');

    cin.ignore();
    return opcao;
}

string leiaNomeProfissao(){
    string nomeProfissao;
    cout << "Informe o nome da profissao correspondente: " << endl;
    cin.ignore();
    getline(cin, nomeProfissao);

    return nomeProfissao;
}

int leiaCodigo(){
    int codigo;
    cout << "Informe o codigo: " << endl;
    cin >> codigo;

    return codigo;
}

void leiaProfissoes(int n, Profissao profissoes[]){
    string nomeProfissao;
    for(int i=0; i<n; i++){
        profissoes[i].codigo = leiaCodigo();
        profissoes[i].nomeProfissao = leiaNomeProfissao();
    }
}

void pesquisaCodigo(int n, int num, Profissao profissoes[]){
    for(int i=0; i<n; i++){
        if(num == profissoes[i].codigo){
            cout << "Profissao identificada: " << profissoes[i].nomeProfissao << endl;
            return;
        }
    }

    cout << "Codigo não identificado" << endl;
}

void pesquisaCodigos(int n, Profissao profissoes[]){
    char opcao;
    int num;
    do {
        cout << "CODIGO A SER PESQUISADO - ";
        num = leiaCodigo();
        pesquisaCodigo(n, num, profissoes);

        opcao = leiaCaracter();
    } while(opcao == 'S');
}

int main()
{
    Profissao profissoes[50];

    int n = leiaQuantidade();

    leiaProfissoes(n, profissoes);
    pesquisaCodigos(n, profissoes);
}
