#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

/*Escreva um programa que imprima na tela 20 linhas por vez � a cada 20 linhas impressas, o programa
s� dever� imprimir as pr�ximas ap�s o usu�rio pressionar <ENTER>. O arquivo de entrada deve ser
informado pelo usu�rio.
*/

int main()
{
    ifstream arquivo;
    string linha, nomeArq;
    int i = 0;

    cout << "Informe o nome do arquivo: " << endl;
    getline(cin, nomeArq);

    arquivo.open(nomeArq.c_str());

    if(!arquivo)
    {
        cout << "Nao foi possivel abrir o arquivo";
        exit(0);
    }

    while(getline(arquivo, linha))
    {
        cout << setw(2) << ++i << " " << linha << endl;

        if(i == 20)
            cin.get();
    }

    return 0;
}
