/*

6) Uma empresa deseja processar os dados sobre seus funcionários. Para tanto, necessita criar um arquivo de
acesso direto CADASTRO.DDO com matrícula, nome e salário. Faça um algoritmo que leia os dados
necessários para criar esse arquivo.

    A seguir deve ser feita uma atualização do arquivo. Essa atualização consiste em ler, para uma quantidade
indeterminada de funcionários, matrícula e código (I ou E, correspondendo a uma inclusão ou exclusão de
funcionário, respectivamente).

    O algoritmo deve ser modularizado, de forma que os seguintes passos sejam executados:

    1. inicialmente é chamado uma subrotina para ler os dados e gerar o arquivo;
    2. a seguir, são lidos matrícula e código. Para código ‘E’ deve ser invocado um procedimento para marcar o
registro correspondente ao funcionário que se deseja excluir. Essa marcação é feita colocando o valor -1 no
campo correspondente a matrícula do funcionário no arquivo; para o código ‘I’ deve ser chamado outra
subrotina para incluir os dados do novo funcionário no arquivo. A inclusão dos dados é sempre feita no final
do arquivo;
    3. depois de feitas todas as operações de inclusão e exclusão, deve ser invocado uma subrotina para atualizar
os dados. Essa atualização consiste em criar um novo arquivo, excluindo fisicamente os registros que
tenham sido marcados anteriormente como logicamente excluídos. O arquivo inicial deve ser apagado.

*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

typedef struct {
    int matricula;
    char nome[21];
    float salario;
} Funcionario;

void criaArquivo(ofstream&, ifstream);
void coletaInfo(Funcionario&);
char leiaOpcao();
void leiaMenu();
void excluiFunc();
void listarInf(ifstream);

int main()
{
    fstream arquivoBIN("CADASTRO.DDO", ios::out | ios::in | ios::binary);

    criaArquivo(arquivoBIN);

    char op;

    do {
        leiaMenu();

        cout << "Informe um opcao: " << endl;
        cin >> op;

        switch (op) {
            case 'E':
                excluiFunc();
                break;
            case 'I':
                //metodo
                break;
            case 'A':
                //metodo
                break;
            case 'L':
                listarInf(arquivoBIN);
                break;
            case 'S':
                //metodo
                break;
        }
    } while (op != 'S');
}

void criaArquivo(fstream &arquivoBIN)
{
    Funcionario f;
    char op;

    cout << "Criando arquio binario..." << endl;

    while (arquivoBIN.is_open())
    {
        do {
            coletaInfo(f);
            arquivoBIN.write((const char*)(&f), sizeof(Funcionario));
            cout << "Gostaria de adicionar mais um funcionario no arquivo?" << endl;
            cin >> op;

            listarInf(arquivoBIN);

            if (op == 'N') {
                arquivoBIN.close();
            }
        } while (op == 'S');
    }
}

void coletaInfo(Funcionario &f) {

    cout << "Informe o número da matricula: ";
    cin >> f.matricula;

    cout << "Informe o nome do funcionario: ";
    cin >> f.nome;

    cout << "Informe o salario do funcionario: ";
    cin >> f.salario;
}

char leiaSN(string mensagem) {
    string opcao;

    cout << mensagem << endl;
    getline(cin, opcao);

    opcao[0] = toupper(opcao[0]);

    while (opcao.size() != 1 or opcao[0] != 'S' and opcao[0] != 'N') {
        cout << "Opcao invalida. Informe novamente: " << endl;
        getline(cin, opcao);
        opcao[0] = toupper(opcao[0]);
    }

    return opcao[0];
}

void leiaMenu() {
    cout << "ESCOLHA UMA DAS OPCOES" << endl;
    cout << "E - Excluir funcionario" << endl;
    cout << "I - Incluir novo funcionario" << endl;
    cout << "A - Criar novo arquivo com as informacoes atualizadas" << endl;
    cout << "L - Listar informacoes" << endl;
    cout << "S - Sair " << endl;
}

char leiaOpcao() {
    string opcao;

    cout << "O que deseja fazer?" << endl;
    getline(cin, opcao);
    opcao[0] = toupper(opcao[0]);

    while (opcao.size() != 1 or opcao[0] < 'A' or opcao[0] > 'H') {
        cout << "Opcao invalida. Informe novamente: " << endl;
        getline(cin, opcao);

        opcao[0] = toupper(opcao[0]);
    }

    return opcao[0];
}

void excluiFunc() {
    int matricula;
    Funcionario f;

    fstream arquivoBIN("CADASTRO.DDO", ios::in | ios::out | ios::binary);

    cout << "Informe a matricula que deseja excluir: " << endl;
    cin >> matricula;

    for (int i = 0; !arquivoBIN.eof(); i += sizeof(Funcionario)) {
        arquivoBIN.read((char*)(&f), sizeof(Funcionario));
        if (matricula == f.matricula) {
            cout << "Achei o funcionario " << f.nome << " com a matricula " << f.matricula << " e fiz sua exclusao logica" << endl;
            f.matricula = -1;
            arquivoBIN.write((const char*)(&f), sizeof(Funcionario));
            break;
        }
    }
}

void listarInf(fstream arquivoBIN) {
    Funcionario f;

    for (int i = 0; !arquivoBIN.eof(); i += sizeof(Funcionario)){
        arquivoBIN.read((char*)(&f), sizeof(Funcionario));

        cout << "Matricula: " << f.matricula << endl;
        cout << "Nome: " << f.nome << endl;
        cout << "Salario: " << f.salario << endl;
    }
}

