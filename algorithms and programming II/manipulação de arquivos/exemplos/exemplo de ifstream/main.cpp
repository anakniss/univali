#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ofstream arquivoS;

    arquivoS.open("exemplo.txt");

    arquivoS << "Nome: ";
    arquivoS << "Ana Clara Kniss\n";
    arquivoS << "Data: ";
    arquivoS << "12/06/2023";

    arquivoS.close();

    ifstream arquivoE;
    string linha;

    arquivoE.open("exemplo.txt");

    if(arquivoE.is_open())
    {
        while(getline(arquivoE, linha))
        {
            cout << linha << endl;
        }

        arquivoE.close();
    }
    else
    {
        cout << "Nao foi possivel abrir o arquivo" << endl;
    }

}
