#include <iostream>

using namespace std;

int main()
{
    string nome;
    char opcao;
    int idade, i = 0;

    do {
        cout << "Informe o nome do aluno: " << endl;
        cin >> nome;
        cout << "Informe a idade do aluno: " << endl;
        cin >> idade;

        if(idade == 18){
            cout << "Nome: " << nome << endl;
            cout << "Idade: " << idade << endl;
        }
        if(idade > 20){
            i++;
            cout << "Quantidade de alunos com mais de 20 anos: " << i << endl;
        }
        cout << "Mais um aluno? S/N" << endl;
        cin >> opcao;
    } while(opcao != 'N');
}
