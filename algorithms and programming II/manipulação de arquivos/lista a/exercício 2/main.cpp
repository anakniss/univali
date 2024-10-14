#include <iostream>
#include <fstream>

using namespace std;

/*Escreva um programa que leia um programa fonte C++ e verifique se o número de chaves esquerdas e
direitas são iguais. O arquivo de entrada deve ser informado pelo usuário. */

int main()
{
    ifstream arquivo;
    string nomeArq;
    char carac;
    int contA = 0;
    int contB = 0;

    cout << "Informe o nome do arquivo a ser aberto: " << endl;
    getline(cin, nomeArq);

    arquivo.open(nomeArq.c_str());

    if(!arquivo)
    {
        cout << "Nao foi possivel abrir o arquivo";
        exit(0);
    }

    while(!arquivo.eof())
    {
        arquivo.get(carac);

        if(carac == '{'){
            contA++;
        }
        else if(carac == '}')
        {
            contB++;
        }
    }

    int result = contA + contB;

    if(result % 2 == 0)
    {
        cout << "Quantidade de chaves validas" << endl;
        cout << "Quantidade de chaves abertas: " << contA << endl;
        cout << "Quantidade de chaves fechadas: " << contB << endl;
    }
    else
    {
        cout << "Quantidade de chaves invalidas" << endl;
        cout << "Quantidade de chaves abertas: " << contA << endl;
        cout << "Quantidade de chaves fechadas: " << contB << endl;
    }

    arquivo.close();

    return 0;
}
