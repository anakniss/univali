#include <iostream>
#include<fstream>

using namespace std;

int main()
{
    fstream arquivo;
    char opcao = 'S';
    string nome, linha;

    //ios::out -> define como saída

    arquivo.open("exemplo.txt", ios::out | ios::app);

    while(opcao == 'S')
    {
        cout << "Digite um nome: " << endl;
        cin >> nome;

        arquivo << nome << "\n";

        cout << "Digitar um novo nome? S/N" << endl;
        cin >> opcao;
    }

    arquivo.close();

    //ios::out -> define como entrada

    arquivo.open("exemplo.txt", ios::in);

    cout << "Nomes digitados" << endl;

    if(arquivo.is_open())
    {
        while(getline(arquivo, linha))
        {
            cout << linha << endl;
        }

        arquivo.close();
    }
    else
    {
        cout << "Nao foi possivel abrir o arquivo" << endl;
    }

    return 0;
}
