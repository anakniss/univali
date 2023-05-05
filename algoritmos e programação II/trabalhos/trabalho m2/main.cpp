#include <iostream>
#define TMAX 50;

using namespace std;

typedef struct {
    string titulo;
    string autor;
    string isbn;
    int qtdAcervo;
    int qtdDisponivel;
} Livro;

typedef struct {
    int dia;
    int mes;
    int ano;
} Data;

typedef struct {
    string matricula;
    string isbn;
    Data data;
} Emprestimo;

char validaCaracter(){
    char op;
    do {
        cout << "O que deseja fazer?" << endl;
        cin.get(op);
    } while(op < 'A' or op > 'G');

    return toupper(op);
}

void lerMenu(){
    cout << "Menu de Biblioteca" << endl;
    cout << "Opcoes: " << endl;
    cout << "A - Inclusao de um novo livro" << endl;
    cout << "B - Consulta a um livro" << endl;
    cout << "C - Exclusao de um livro" << endl;
    cout << "D - Emprestimo de um exemplar" << endl;
    cout << "E - Devolucao" << endl;
    cout << "F - Relatorio: Livros do Acervo" << endl;
    cout << "G - Relatorio: Emprestimos" << endl;
}

void inclusaoNovoLivro(int &n, Livro acervo[]){
    Livro l;
    cout << "Informe o titulo do livro a ser adicionado: " << endl;
    getline(cin, l.titulo);
    cout << "Informe o nome do autor do livro: " << endl;
    getline(cin, l.autor);
    cout << "Informe a quantidade do acervo: " << endl;
    cin >> l.qtdAcervo;
    acervo[n] = l;
    l.qtdDisponivel = l.qtdAcervo;
    n++;
}

bool comparaStrings(string a, string b){
    int tam;

    if(a.size() > b.size()){
        tam = b.size();
    }
    else {
        tam = a.size();
    }

    for(int i=0; i<tam; i++){
        if(a[i] > b[i]){
            return true;
        }
        else {
            if(b[i] > a[i]){
                return false;
            }
        }
    }

    if(a.size() > b.size()){
        return true;
    }
    else {
        return false;
    }
}

void ordenaBubbleSort(Livro acervo[], int n){
    int maior = 0;
    Livro aux;
    for(int i=0; i<n; i++){
        for(int j=0; j< n-i-1; j++){
            maior = comparaStrings(acervo[j].isbn, acervo[j+1].isbn);
            if(maior != true){
                aux = acervo[j];
                acervo[j] = acervo[j+1];
                acervo[j+1] = aux;
            }
        }
    }
}

void pesquisaRecBinaria(){

}

int main()
{
    char op;
    int n = 0;

    Livro acervo[50];
    Emprestimo emprestimos[50];

    lerMenu();
    op = validaCaracter();

    switch (op) {
        case 'A':
            cout << "Informe o c�digo do ISBN do livro: " << endl;
            getline(cin, l.isbn);
            int iPesq = pesquisaRecBinaria();
            if (iPesq < 0)
                inclusaoNovoLivro();
            else
                cout << "Livro ja cadastrado" << endl;

            break;
        case 'B':
            break;
        case 'C':
            break;
        case 'D':
            break;
        case 'F':
            break;
        case 'G':
            break;
    }
}
