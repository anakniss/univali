#include <iostream>
#include <iomanip>
#include <string>
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

char leiaCaracter(){
    char opcao;

    cout << "O que deseja fazer?" << endl;
    cin.get(opcao);
    cin.ignore();
    opcao = toupper(opcao);

    while(opcao < 'A' or opcao > 'H'){
        cout << "Opcao invalida. Informe novamente: " << endl;
        cin.get(opcao);
        cin.ignore();
    }

    return opcao;
}

int comparaStrings(string a, string b){
    int tam;

    if(a.size() > b.size()){
        tam = b.size();
    }
    else {
        tam = a.size();
    }

    for(int i=0; i<tam; i++){
        if(a[i] > b[i]){
            return 1;
        }
        else {
            if(b[i] > a[i]){
                return -1;
            }
        }
    }

    if(a.size() > b.size()){
        return 1;
    }
    else {
        if(a.size() == b.size()){
            return 0;
        }
        else {
            return -1;
        }
    }
}

void ordenaBubbleSort(Livro acervo[], int n){
    int comp = 0;
    Livro aux;
    for(int i=0; i<n; i++){
        for(int j=0; j< n-i-1; j++){
            comp = comparaStrings(acervo[j].isbn, acervo[j+1].isbn);
            if(comp == 1){
                aux = acervo[j];
                acervo[j] = acervo[j+1];
                acervo[j+1] = aux;
            }
        }
    }
}

int pesquisaRecBinaria(string chave, Livro acervo[], int inicio, int fim){

    if(inicio <= fim){
        int meio = (inicio + fim) / 2;
        int comp = comparaStrings(chave, acervo[meio].isbn);

        if(comp == 0){
            return meio;
        }

        else {
            if(comp == -1){
                return pesquisaRecBinaria(chave, acervo, inicio, meio - 1);
            }
            else {
                return pesquisaRecBinaria(chave, acervo, meio + 1, fim);
            }
        }
    }
    return -1;
}

bool pesquisaRecBinaria2(int chave, int acervo[], int inicio, int fim){

    if(inicio <= fim){
        int meio = (inicio + fim) / 2;

        if(chave == acervo[meio]){
            return true;
        }

        else {
            if(chave < acervo[meio]){
                return pesquisaRecBinaria2(chave, acervo, inicio, meio - 1);
            }
            else {
                return pesquisaRecBinaria2(chave, acervo, meio + 1, fim);
            }
        }
    }
    return false;
}


bool validaISBN(string isbn){
    if(isbn.size() != 17){
        return false;
    }
    for(int j=0; j<3; j++){
        if(isdigit(isbn[j]) == false){
            return false;
        }
    }
    if(isbn[3] != '-'){
        return false;
    }
    if(isdigit(isbn[4]) == false){
        return false;
    }
    if(isbn[5] != '-'){
        return false;
    }
    if(isdigit(isbn[6]) == false or isdigit(isbn[7]) == false){
        return false;
    }
    if(isbn[8] != '-'){
        return false;
    }
    for(int j=9; j<15; j++){
        if(isdigit(isbn[j]) == false){
            return false;
        }
    }

    if(isbn[15] != '-'){
        return false;
    }
    if(isdigit(isbn[16]) == false){
        return false;
    }
    return true;
}

void leiaISBN(string &isbn){
    bool result;
    cout << "Informe o codigo ISBN com o seguinte padrao: '978-3-16-148410-0' " << endl;
    getline(cin, isbn);
    result = validaISBN(isbn);

    while(result == false){
        cout << "Codigo ISBN invalido. Informe o valor que corresponda ao seguinte exemplo: '978-3-16-148410-0': " << endl;
        getline(cin, isbn);
        result = validaISBN(isbn);
    }
}

void leiaMenu(){
    cout << "Menu de Biblioteca" << endl;
    cout << "Opcoes: " << endl;
    cout << "A - Inclusao de um novo livro" << endl;
    cout << "B - Consulta a um livro" << endl;
    cout << "C - Exclusao de um livro" << endl;
    cout << "D - Emprestimo de um exemplar" << endl;
    cout << "E - Devolucao" << endl;
    cout << "F - Relatorio: Livros do Acervo" << endl;
    cout << "G - Relatorio: Emprestimos" << endl;
    cout << "H - Sair" << endl;
}

void leiaString(string mensagem, string &nome){
    cout << mensagem << endl;
    cin.ignore();
    getline(cin, nome);

    while(nome.size() == 0){
        cout << "Valor vazio. Informe novamente: " << endl;
        getline(cin, nome);
    }
}

void leiaInteiro(string mensagem, int &num){
    do {
        cout << mensagem << endl;
        cin >> num;
        cin.ignore();
    } while(num < 0);
}

void incluaNovoLivro(int &n, Livro acervo[]){
    Livro l;
    int result;
    leiaISBN(l.isbn);

    result = pesquisaRecBinaria(l.isbn, acervo, 0, n-1);

    if(result == -1){
        leiaString("Informe o titulo do livro a ser adicionado: ", l.titulo);
        leiaString("Informe o nome do autor do livro: ", l.autor);
        leiaInteiro("Informe a quantidade do acervo: ", l.qtdAcervo);
        l.qtdDisponivel = l.qtdAcervo;
        acervo[n] = l;
        n++;
    }
    else {
        cout << "Titulo ja existente";
    }

    ordenaBubbleSort(acervo, n);

}

void relatorioLivrosAcervo(int &n, Livro acervo[]){
    for(int i=0; i<n; i++){
        cout << "ISBN: " << acervo[i].isbn << endl;
        cout << "Titulo: " << acervo[i].titulo << endl;
        cout << "Autor: " << acervo[i].autor << endl;
        cout << "Quantidade do acervo: " << acervo[i].qtdAcervo << endl;
        cout << "Quantidade disponivel: " << acervo[i].qtdDisponivel << endl;
        cout << "==========================================" << endl;
    }
}

void consultaLivro(int n, Livro acervo[]){
    int result;
    string chave;

    leiaISBN(chave);

    result = pesquisaRecBinaria(chave, acervo, 0, n-1);
    if(result == -1){
       cout << "Titulo inexistente" << endl;
    }
    else{
        cout << "ISBN: " << acervo[result].isbn << endl;
        cout << "Titulo: " << acervo[result].titulo << endl;
        cout << "Autor: " << acervo[result].autor << endl;
        cout << "Quantidade do acervo: " << acervo[result].qtdAcervo << endl;
        cout << "Quantidade disponivel: " << acervo[result].qtdDisponivel << endl;
    }
}

void exclusaoLivro(int &n, Livro acervo[]){
    int result;
    string chave;

    leiaISBN(chave);

    result = pesquisaRecBinaria(chave, acervo, 0, n-1);
    if(result == -1){
       cout << "Titulo inexistente, impossivel excluir" << endl;
    }
    else{
        for(int i=result; i<n-1; i++){
            acervo[i] = acervo[i+1];
        }
        n--;
    }
}
/*
int main(){
    int acervo[] = {1, 4, 5, 7, 8, 9, 10};
    bool result = pesquisaRecBinaria2(10, acervo, 0, 6);
    cout << result;

}
*/
int main()
{
    char opcao;
    int n = 0;

    Livro acervo[50];
    Emprestimo emprestimos[50];

    do {
        leiaMenu();
        opcao = leiaCaracter();
        switch (opcao) {
            case 'A':
                incluaNovoLivro(n, acervo);
                break;
            case 'B':
                consultaLivro(n, acervo);
                break;
            case 'C':
                exclusaoLivro(n, acervo);
                break;
            case 'D':
                break;
            case 'F':
                relatorioLivrosAcervo(n, acervo);
                break;
            case 'G':
                break;
        }
    } while(opcao != 'H');
}
