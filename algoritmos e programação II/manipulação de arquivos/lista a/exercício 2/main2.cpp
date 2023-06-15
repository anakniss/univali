#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

/*Escreva um programa que numere as linhas de um arquivo. O arquivo de entrada deve ser informado
pelo usuário. O programa deve mostrar cada linha do arquivo de entrada precedida do seu número e um
espaço.*/

int main() {
    ifstream arquivoIN;    // arquivo para leitura
    string linha, nomearq;

    int i=0;

    cout << "\nNome do arquivo a ser aberto: ";
    getline(cin, nomearq);

    arquivoIN.open(nomearq.c_str()); // abre para leitura

    ofstream arquivoOUT("fontenew.txt");

    if (!arquivoIN or !arquivoOUT) {
        cout << "Nao foi possivel abrir um dos arquivos.";
        cin.get();

        exit(0);
    }

    while (getline(arquivoIN,linha)){ //leitura da linha usada como teste do while
        arquivoOUT << setw(2) << ++i << " " << linha << endl;
    }

    arquivoIN.close();
    arquivoOUT.close();

    arquivoIN.open("fontenew.txt"); // abre para leitura

    if (!arquivoIN)
    {
        cout << "Nao foi possivel abrir os arquivos."; cin.get();
        return 0;
    }

    // leitura da linha usada como teste do while
    while (getline(arquivoIN,linha))    {
        cout << linha << endl;
    }
    arquivoIN.close();
    return 0;
}
