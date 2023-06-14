#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>

using namespace std;

/*Considere um arquivo de acesso direto com código (inteiro), nome (string) e quantidade (inteiro) de uma
série de produtos. Elabore um algoritmo que i) crie e preencha uma estrutura em memória para
armazenar estes dados; ii) a partir de um arquivo de acesso sequencial contendo código (inteiro),
operação (caracter) – onde operação pode ser C (compra) ou V (venda) – e quantidade (inteiro), atualize
os dados dos produtos na lista; iii) atualize o arquivo de acesso direto com as informações da lista e iv)
finalize o processo.
*/

void gravaProdutos();
void mostraProdutos();

typedef struct {
    int cod;
    char nome[51];
    int qtde;
} Produto;

int main()
{
    gravaProdutos();
    mostraProdutos();

    return 0;
}

void gravaProdutos()
{
    Produto p;
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

void mostraProdutos()
{
    Produto p;
    ifstream arq("PRODUTOS.BIN", ios::binary);
    if(arq.fail())
    {
        cout << "Arquivo com problema";
        exit(0);
    }
    while(arq.read((char*)(&p), sizeof(Produto)))
    {
        cout << p.cod << " " << p.qtde << " " << p.nome << endl;
    }

    arq.close();
}

void atualizaProduto()
{
    fstream arq2("PRODUTOS.BIN", ios::binary | ios::out | ios::ate);
    ifstream arq1("MVTO.TXT");
    string linha;
    char tipo;
    int valor, cod;
    Produto p;

    cout << endl << "Iniciando atualizacao de produtos" << endl;
    if(arq1.fail()){
        cout << "problema com MVTO.TXT";
        exit(0);
    }
    while(getline(arq1, linha))
    {
        cod = stoi(linha.substr(0, 1));
        tipo = toupper(linha.at(2));
        valor = stoi(linha.substr(4, 2));
        cout << cod << " " << tipo << " " << valor << endl;
        arq2.seekg(0, ios::beg);

        do
        {
            arq2.read((char*)(&p), sizeof(Produto));
            if(p.cod == cod)
            {
                cout << "atualizando " << p.cod << endl;
                if(tipo == 'C')
                    p.qtde += valor;
                else
                    p.qtde -= valor;

                arq2.seekp(-sizeof(Produto), ios::cur);
                arq2.write((const char*)(&p), sizeof(Produto));

                break;

            }
        } while(not arq2.eof());

        arq1.close();
        arq2.close();
    }
}
