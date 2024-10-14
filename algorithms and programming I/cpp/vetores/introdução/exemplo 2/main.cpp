#include <iostream>

using namespace std;
#define TMAX 4

//Leia o nome de 4 alunos e os escreva na tela de forma inversa utilizando um vetor de caracteres e string

int main()
{
    string nomes[TMAX];

    for(int i = 0; i < TMAX; i++){
        cout << "Digite o nome do aluno: ";
        getline(cin, nomes[i]);
    }

    cout << "=====================================" << endl;

    for(int i = TMAX - 1; i >= 0; i--){
        cout << nomes[i] << endl;
    }
}
