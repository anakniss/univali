#include <iostream>

using namespace std;

int main()
{
    char ident, situacao;
    int i, j, qntdAlunos, qntdAlunosPresentes = 0, qntdAlunosAusentes = 0, matricula;
    float nota, media = 0;

    for(i = 0; i < 2; i++){
        cout << "Informe a identifica��o da turma: " << endl;
        cin >> ident;

        cout << "Informe a quantidade de alunos matriculados: " << endl;
        cin >> qntdAlunos;

        for(j = 0; j < qntdAlunos; j++){
            cout << "Informe o n�mero de matr�cula do aluno: " << endl;
            cin >> matricula;

            cout << "Informe a situa��o de presen�a do aluno (A para ausente e P para presente): " << endl;
            cin >> situacao;

            if(situacao == 'P'){
                qntdAlunosPresentes++;

                cout << "Informe a nota que o aluno tirou: " << endl;
                cin >> nota;

                media += nota;
            }
            else {
                qntdAlunosAusentes++;
                cout << qntdAlunosAusentes;
            }
        }

        cout << "Identifica��o da turma: " << ident << endl;
        cout << "Porcentagem de alunos ausentes: " << (qntdAlunosAusentes / float(qntdAlunos)) * 100 << "%" << endl;
        cout << "M�dia da turma: " << media / float(qntdAlunosPresentes) << endl;

        qntdAlunosPresentes = 0;
        qntdAlunosAusentes = 0;

        media = 0;
    }
}
