#include <iostream>

using namespace std;

int main()
{
    int matricula;
    float nota1, nota2, nota3, mediaExercicios, mediaAproveitamento;

    cout << "Informe a matrícula: " << endl;
    cin >> matricula;

    cout << "Informe a primeira nota: " << endl;
    cin >> nota1;
    cout << "Informe a segunda nota: " << endl;
    cin >> nota2;
    cout << "Informe a terceira nota: " << endl;
    cin >> nota3;

    mediaExercicios = (nota1 + nota2 + nota3) / 3;
    mediaAproveitamento = ((nota1 + (nota2 * 2) + (nota3 * 3) + mediaExercicios)) / 7;

    if (mediaAproveitamento >= 6.0){

        cout << "Matrícula: " << matricula << endl;
        cout << "Nota 1: " << nota1 << endl;
        cout << "Nota 2: " << nota2 << endl;
        cout << "Nota 3: " << nota3 << endl;
        cout << "Média dos exercícios: " << mediaExercicios << endl;
        cout << "Média de aproveitamento: " << mediaAproveitamento << endl;
        cout << "Aluno APROVADO" << endl;

        if (mediaAproveitamento >= 9.0){

        cout << "O aluno obteve conceito A" << endl;
        }

        else if (mediaAproveitamento >= 7.5 &&  mediaAproveitamento < 9.0){

        cout << "O aluno obteve conceito B" << endl;
        }

        else {

        cout << "O aluno obteve conceito C" << endl;

        }
    }

    if (mediaAproveitamento < 6.0){
        cout << "Matrícula: " << matricula << endl;
        cout << "Nota 1: " << nota1 << endl;
        cout << "Nota 2: " << nota2 << endl;
        cout << "Nota 3: " << nota3 << endl;
        cout << "Média dos exercícios: " << mediaExercicios << endl;
        cout << "Média de aproveitamento: " << mediaAproveitamento << endl;
        cout << "Aluno REPROVADO" << endl;

        if (mediaAproveitamento >= 4.0 && mediaAproveitamento < 6.0){

            cout << "O aluno obteve conceito D" << endl;

        }

        else {
            cout << "O aluno obteve conceito E" << endl;
        }
    }






}
