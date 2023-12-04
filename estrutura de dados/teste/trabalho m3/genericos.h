#ifndef GENERICOS_H_INCLUDED
#define GENERICOS_H_INCLUDED

#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib> 

using namespace std;

void mostraMenu() {
    cout << "MENU" << endl;
    cout << "1. Criar arquivo com 10000 dados" << endl;
    cout << "2. Ler arquivo" << endl;
    cout << "6. Sair" << endl;
}

bool validaNumeroIntPositivo(string num) {
    if (num != "") {
        for (int i = 0; i < num.size(); i++)
            if (not isdigit(num[i]))
                return false;
    }
    else
        return false;
    return true;
}

int leiaNumero(string mensagem) {
    string num;
    cout << mensagem;
    getline(cin, num);
    while (not validaNumeroIntPositivo(num)) {
        cout << "Dado invalido. Informe novamente: ";
        getline(cin, num);
    }
    return atoi(num.c_str());
}

void criaArquivo() {
    ofstream arquivo("dados_ordem_crescente.txt");

    if (!arquivo.is_open()) {
        cout << "Erro ao criar o arquivo." << endl;
    }

    int quantidadeDados = 10000;
    int ultimo = 0;

    for (int i = 0; i < quantidadeDados; i++){
        ultimo = ultimo + rand() % 9 + 1;
        arquivo << ultimo << endl;
    }

    arquivo.close();

    cout << "Arquivo criado com sucesso com 10000 dados em ordem crescente." << endl;
}

#endif // GENERICOS_H_INCLUDED
