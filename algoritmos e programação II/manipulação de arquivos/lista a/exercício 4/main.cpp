#include <iostream>
#include <fstream>

using namespace std;

/*Escreva um programa que leia um programa fonte C++ e retire os comentários deste programa fonte. O
novo arquivo deve ser gravado com o mesmo nome, porém com extensão xxx. O arquivo de entrada
deve ser informado pelo usuário.*/

int main()
{
    ifstream arquivo1;
    ofstream arquivo2;

    string nomeArq, nomeArq2;

    char ch;

    bool flag = false;

    cout << "Informe o nome do arquivo: " << endl;
    getline(cin, nomeArq);

    arquivo1.open(nomeArq.c_str());

    nomeArq2 = nomeArq;

    for(int i = nomeArq2.size()-1; i > 0; i--)
    {
        if(nomeArq2.at(i) != '.') {
            nomeArq2.at(i) = 'x';
            }
        else
            break;
    }

    arquivo2.open(nomeArq2.c_str());

    if(!arquivo1 and !arquivo2)
    {
        cout << "Nao foi possivel abrir o arquivo";
        exit(0);
    }

    cout << "Nome do arquivo: " << nomeArq2 << endl;

    while(!arquivo1.eof())
    {
        arquivo1.get(ch);

        if(flag == true)
            if(ch == '\\' or ch == '*')
            {
                flag = false;
                break;
            }
        else if(ch == '\\')
            flag = true;
        else
            arquivo2 << ch;
    }

    arquivo1.close();
    arquivo2.close();

    return 0;
}
