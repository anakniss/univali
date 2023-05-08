#include <iostream>
#include <iomanip>
#include <string>
#define TMAX 50

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
    int matricula;
    string isbn;
    Data data;
} Emprestimo;

char leiaOpcao();
char leiaSN(string);
void leiaData(string, int &, int &, int &);
int comparaStrings(string, string);
void ordenaBubbleSortRecursivo(int, Livro []);
int pesquisaRecBinaria(string, Livro [], int, int);
bool validaISBN(string);
void leiaISBN(string &);
void leiaMenu();
void leiaString(string, string &);
void leiaInteiro(string, int &);
void incluaNovoLivro(int &, Livro []);
void mostraLivro(int, Livro []);
void mostraEmprestimo(int, Emprestimo []);
void relatorioLivrosAcervo(int, Livro[]);
void consultaLivro(int, Livro []);
void excluaLivro(int &, Livro []);
void emprestaExemplarLivro(int &, int &, Livro [], Emprestimo []);
void devolvaLivro(int &, int, Livro [], Emprestimo []);
void mostraRelatorioLivrosAcervo(int, Livro []);
void mostraRelatorioEmprestimosAtivos(int, Emprestimo []);

char leiaOpcao(){
    char opcao;

    cout << "O que deseja fazer?" << endl;
    cin.get(opcao);
    cin.ignore();
    opcao = toupper(opcao);

    while(opcao < 'A' or opcao > 'H'){
        cout << "Opcao invalida. Informe novamente: " << endl;
        cin.get(opcao);

        opcao = toupper(opcao);
        cin.ignore();
    }

    return opcao;
}

char leiaSN(string mensagem){
    char opcao;

    cout << mensagem << endl;
    cin.get(opcao);
    cin.ignore();
    opcao = toupper(opcao);

    while(opcao != 'S' and opcao != 'N'){
        cout << "Opcao invalida. Informe novamente: " << endl;
        cin.get(opcao);
        cin.ignore();

        opcao = toupper(opcao);
    }

    return opcao;
}

void leiaData(string mensagem, int &dia, int &mes, int &ano){
    cout << mensagem << endl;

    leiaInteiro("Informe o dia: ", dia);

    while(dia < 1 or dia > 31){
        leiaInteiro("Valor do dia invalido. Informe novamente: ", dia);
    }

    leiaInteiro("Informe o mes: ", mes);

    while(mes < 1 or mes > 12){
        leiaInteiro("Valor do mes invalido. Informe novamente: ", mes);
    }

    leiaInteiro("Informe o ano (4 digitos): ", ano);

    while(ano < 1940 or ano > 2023){
        leiaInteiro("Valor do ano invalido. Informe novamente: ", ano);
    }
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
        else if(b[i] > a[i]){
                return -1;
        }
    }

    if(a.size() > b.size()){
        return 1;
    }
    else if(a.size() == b.size()){
        return 0;
    }
    else {
        return -1;
    }
}

void ordenaBubbleSortRecursivo(int n, Livro acervo[]){
    int comp;
    if(n == 1){
        return;
    }

    for(int i=0; i < n-1; i++){
        comp = comparaStrings(acervo[i].isbn, acervo[i+1].isbn);
        if(comp == 1){
            swap(acervo[i].isbn, acervo[i+1].isbn);
        }
    }
    ordenaBubbleSortRecursivo(n-1, acervo);
}

int pesquisaRecBinaria(string chave, Livro acervo[], int inicio, int fim){
    if(inicio <= fim){
        int meio = (inicio + fim) / 2;
        int comp = comparaStrings(chave, acervo[meio].isbn);

        if(comp == 0){
            return meio;
        }
        else if(comp == -1){
            return pesquisaRecBinaria(chave, acervo, inicio, meio - 1);
        }
        else {
            return pesquisaRecBinaria(chave, acervo, meio + 1, fim);
        }
    }
    return -1;
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
    cout << "Informe o codigo ISBN (ex: 132-2-11-321543-3)" << endl;
    getline(cin, isbn);
    result = validaISBN(isbn);

    while(result == false){
        cout << "Codigo ISBN invalido. Informe um codigo valido (ex: 132-2-11-321543-3)" << endl;
        getline(cin, isbn);
        result = validaISBN(isbn);
    }
}

void leiaMenu(){
    cout << "Menu da Biblioteca" << endl;
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
    getline(cin, nome);

    while(nome.size() == 0){
        cout << "Valor vazio. Informe novamente: " << endl;
        cin.ignore();
        getline(cin, nome);
    }
}

void leiaInteiro(string mensagem, int &num){
    cout << mensagem << endl;
    cin >> num;
    while(cin.fail()) {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Dado invalido. Informe novamente" << endl;
        cin >> num;
    }
    cin.ignore();
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

    ordenaBubbleSortRecursivo(n, acervo);

}

void mostraLivro(int i, Livro acervo[]){
    cout << "ISBN: " << acervo[i].isbn << endl;
    cout << "Titulo: " << acervo[i].titulo << endl;
    cout << "Autor: " << acervo[i].autor << endl;
    cout << "Quantidade do acervo: " << acervo[i].qtdAcervo << endl;
    cout << "Quantidade disponivel: " << acervo[i].qtdDisponivel << endl;
}

void mostraEmprestimo(int i, Emprestimo e[]){
    cout << "Matricula: " << e[i].matricula << endl;
    cout << "Data: " << e[i].data.dia << "/" << e[i].data.mes << "/" << e[i].data.ano << endl;
    cout << "ISBN: " << e[i].isbn << endl;
}

void mostraRelatorioLivrosAcervo(int n, Livro acervo[]){
    if(n == 0){
            cout << "Nao existem dados a serem informados" << endl;
    }
    for(int i=0; i<n; i++){
        mostraLivro(i, acervo);
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
        mostraLivro(result, acervo);
    }
}

void excluaLivro(int &n, Livro acervo[]){

    int result;
    string chave;
    char opcao;

    leiaISBN(chave);

    result = pesquisaRecBinaria(chave, acervo, 0, n-1);
    if(result == -1){
       cout << "Titulo inexistente, impossivel excluir" << endl;
    }
    else{
        mostraLivro(result, acervo);
        opcao = leiaSN("Deseja mesmo excluir o livro? S/N");

        if(opcao == 'S'){
            for(int i=result; i<n-1; i++){
            acervo[i] = acervo[i+1];
            }
            n--;
            cout << "Exclusao realizada" << endl;
        }
    }
}

void emprestaExemplarLivro(int &n, int &l, Livro acervo[], Emprestimo emprestimos[]){
    int result;
    string chave;
    Emprestimo e;

    leiaISBN(chave);

    result = pesquisaRecBinaria(chave, acervo, 0, n-1);
    if(result == -1){
       cout << "Titulo inexistente" << endl;
    }
    else{
        if(acervo[result].qtdDisponivel > 0){
            leiaInteiro("Informe a matricula: ", e.matricula);
            leiaData("Data do emprestimo", e.data.dia, e.data.mes, e.data.ano);
            e.isbn = acervo[result].isbn;
            emprestimos[l] = e;
            cout << "Emprestimo realizado - codigo " << l << endl;
            acervo[result].qtdDisponivel--;
            l++;
        }
        else {
            cout << "Exemplar indisponivel para emprestimo" << endl;
        }
    }
}

void devolvaLivro(int &l, int n, Livro acervo[], Emprestimo e[]){
    int codigo;
    int result;
    char opcao;
    leiaInteiro("Informe o codigo do emprestimo: ", codigo);

    if(codigo >= l){
        cout << "Registro inexistente" << endl;
    }
    else {
        if(e[codigo].matricula == -1){
            cout << "Devolucao ja realizada" << endl;
        }
        else {
            result = pesquisaRecBinaria(e[codigo].isbn, acervo, 0, n-1);
            if(result == 0){
                mostraEmprestimo(codigo, e);

                opcao = leiaSN("Deseja mesmo devolver o livro? S/N");

                if(opcao == 'S'){
                    e[codigo].matricula = -1;
                    acervo[result].qtdDisponivel++;
                    l--;
                    cout << "Devolucao realizada" << endl;
                }
            }
        }
    }
}

void mostraRelatorioEmprestimosAtivos(int l, Emprestimo e[]){
    cout << "L: " << l << endl;
    if(l == 0){
            cout << "Nao existem dados a serem informados" << endl;
    }
    for(int i=0; i<l; i++){
        if(e[i].matricula != -1){
            mostraEmprestimo(i, e);
            cout << "==========================================" << endl;
        }
    }
}

int main()
{
    char opcao;
    int n = 0;
    int l = 0;

    Livro acervo[TMAX];
    Emprestimo emprestimos[TMAX];

    do {
        leiaMenu();
        opcao = leiaOpcao();
        switch (opcao) {
            case 'A':
                incluaNovoLivro(n, acervo);
                break;
            case 'B':
                consultaLivro(n, acervo);
                break;
            case 'C':
                excluaLivro(n, acervo);
                break;
            case 'D':
                emprestaExemplarLivro(n, l, acervo, emprestimos);
                break;
            case 'E':
                devolvaLivro(l, n, acervo, emprestimos);
                break;
            case 'F':
                mostraRelatorioLivrosAcervo(n, acervo);
                break;
            case 'G':
                mostraRelatorioEmprestimosAtivos(l, emprestimos);
                break;
        }
    } while(opcao != 'H');
}
