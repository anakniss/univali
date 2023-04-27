#include <iostream>

using namespace std;

struct Alunos{
    string nome;
    float notas[4];
    float media;
};

struct Turma{
    Alunos alunos[20];
};

int main()
{
    Turma turmaA;
    Turma turmaB;

    for(int i=0; i<20; i++){
        float soma = 0;
        float media;

        cout << "Informe o nome do aluno " << i+1 << ": " << endl;
        cin.ignore();
        getline(cin, turmaA.alunos[i].nome);

        for(int j=0; j<4; j++){
            cout << "Informe a nota " << j+1 << " do aluno: " << endl;
            cin >> turmaA.alunos[i].notas[j];

            soma += turmaA.alunos[i].notas[j];
        }

        media = soma / 4;
        cout << "Média do aluno " << i+1 << ": " << media << endl;
    }

    for(int i=0; i<20; i++){
        float soma = 0;
        float media;

        cout << "Informe o nome do aluno " << i+1 << ": " << endl;
        cin.ignore();
        getline(cin, turmaB.alunos[i].nome);

        for(int j=0; j<4; j++){
            cout << "Informe a nota " << j+1 << " do aluno: " << endl;
            cin >> turmaB.alunos[i].notas[j];

            soma += turmaB.alunos[i].notas[j];
        }

        media = soma / 4;
        cout << "Média do aluno " << i+1 << ": " << media << endl;
    }
}
