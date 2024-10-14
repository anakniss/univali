#include <iostream>

using namespace std;

/*Faça um algoritmo que leia o nome, sexo, cor dos olhos, altura, peso e data de nascimento de n
pessoas e crie um arquivo de acesso direto chamado CADASTRO. Após, leia o arquivo anterior e gere
outros dois arquivos de acesso direto chamados HOMENS e MULHERES para armazenar os dados das
pessoas do sexo masculino e feminino, respectivamente. O sexo das pessoas não deverá ser
armazenado nos novos arquivos.*/

typedef struct {
    char nome[51];
    char dataNascimento;
    char sexo;
    char corOlhos[10];
    float altura, peso;
} Cadastro;

int main()
{
    return 0;
}

void gravaCadastro()
{
    Cadastro p;
    string nome;
    char resp;
    int i=0;
    ofstream arq("PRODUTOS.bin", ios::binary);
    if(arq.fail())
    {
        cout << "Arquivo nao pode ser aberto";
        exit(0);
    }
    do
    {
        cout << "Produto " << ++i << endl;
        p.cod = i;
        cout << "Informe nome: ";
        getline(cin, nome);
        strcpy(p.nome, nome.c_str());
        cout << "Informe qtde do produto: ";
        cin >> p.qtde;
        cin.ignore();
        arq.write((const char*) (&p), sizeof(Produto));
        cout << "Outro? S/N";
        resp = toupper(cin.get());
        cin.ignore();


    } while(resp == 'S');

    arq.close();
}
