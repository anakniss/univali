#include <iostream>
#include <fstream>
#include <string>

using namespace std;

/*Faça um algoritmo que leia um arquivo de acesso seqüencial onde cada linha tem no máximo 80 caracteres e
formate este arquivo de modo que cada linha seja centralizada. */

int main()
{
    string linha;
    int tam;

    rename("ana.txt", "ana.bak");
    ifstream arquivoIN("ana.bak");
    ofstream arquivoOUT("ana.txt");
    
    if (!arquivoIN.is_open()) {
        cout << "error";
        exit(0);
    }

    while (getline(arquivoIN, linha)) {
        tam = (80 - linha.size()) / 2;
        for (int i = 1; i <= tam; i++)
            arquivoOUT << ' ';

        arquivoOUT << linha << endl;
    }

    arquivoIN.close();
}


