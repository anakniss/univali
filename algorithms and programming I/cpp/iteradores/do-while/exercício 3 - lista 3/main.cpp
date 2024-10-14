#include <iostream>

using namespace std;

int main()
{
    float altura, mediaMulheres = 0, mediaTurma = 0;
    char sexo, opcao;
    int iM = 0, iT = 0;

    do {
        cout << "Informe a altura: " << endl;
        cin >> altura;
        cout << "Informe o sexo: " << endl;
        cin >> sexo;

        if(sexo == 'F'){
            iM++;
            mediaMulheres = mediaMulheres + altura;
        }

        cout << "Média atual da altura das mulheres: " << mediaMulheres / iM << endl;

        iT++;
        mediaTurma = mediaTurma + altura;
        cout << "A média de altura da turma é de: " << mediaTurma / iT << endl;

        cout << "Mais um aluno? S/N" << endl;
        cin >> opcao;

    } while(opcao != 'N');
}
