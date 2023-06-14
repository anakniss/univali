#include <iostream>
#include <fstream>
using namespace std;
const int MAX_FUNCS = 3;

typedef struct {
    int codigo;
    char nome[50]; // tem q ser string no padrao C (vetor de char)
    float salario;
    char sexo;
} Funcionario;

void leFuncionarios(Funcionario f[], int quantidade){
    string nome;
    for (int i = 0; i < quantidade; i++){
        cout << "Leitura de dados de um funcionario\n\n";
        cout << "Codigo.: ";
        cin >> f[i].codigo;
        cin.ignore();
        cout << "Nome...: ";
        getline(cin,nome); strcpy(f[i].nome, nome.c_str());
        cout << "Salario: ";
        cin >> f[i].salario; cin.ignore();
        cout << "Sexo...: ";
        cin >> f[i].sexo; cin.ignore();
    }
}

void mostraFuncionarios(Funcionario f[], int quantidade){
    for (int i = 0; i < quantidade; i++) {
        cout << "Leitura de dados de um funcionario\n\n";
        cout << "Codigo.: " << f[i].codigo << endl;
        cout << "Nome...: " << f[i].nome << endl;
        cout << "Salario: " << f[i].salario << endl;
        cout << "Sexo...: " << f[i].sexo << endl;
    }
}

void gravaFuncionarios(ofstream &ofs, Funcionario f[], int quantidade){
// grava a quantidade de funcionarios
    ofs.write((char*)&quantidade, sizeof(int));
// grava cada um dos funcionários como um vetor de caracteres
    for (int i = 0; i < quantidade; i++)
        ofs.write((const char*)(&f[i]), sizeof(f[i]));
}

void recupFuncionarios(ifstream &ifs, Funcionario f[], int &quantidade){
    // lê o número de funcionários gravados no cabeçalho
    ifs.read((char*)&quantidade, sizeof(int));
    // lê os dados
    for (int i = 0; i < quantidade; i++)
        ifs.read((char*)(&f[i]), sizeof(f[i]));
}

int main(){
    string nomeArquivo;
    Funcionario funcionarios[MAX_FUNCS], lidos[MAX_FUNCS];
    ofstream ofs;
    leFuncionarios(funcionarios, MAX_FUNCS); // preenche vetor c/dados
    cout << "Nome do arquivo: ";
    getline(cin,nomeArquivo);
    ofs.open(nomeArquivo.c_str(), ios::out | ios::binary);
    if(!ofs){
        cout << "Arquivo: " << nomeArquivo << " nao pode ser aberto para escrita." << endl;
    }else{
    // grava informações do vetor no arquivo e fecha arquivo
        gravaFuncionarios(ofs, funcionarios, MAX_FUNCS);
        ofs.close();
}

    cout << "\nRecuperando os dados do arquivo";
    ifstream ifs(nomeArquivo.c_str(), ios::binary);
    if(!ifs){
        cout << "Arquivo: " << nomeArquivo << " nao pode ser aberto para leitura." << endl;
    }else{
        int quantidade = 0;
        // lê as informações do arquivo e mostra
        recupFuncionarios(ifs, lidos, quantidade);
        mostraFuncionarios(lidos, quantidade);
        ifs.close();
    }

    return 0;
}
