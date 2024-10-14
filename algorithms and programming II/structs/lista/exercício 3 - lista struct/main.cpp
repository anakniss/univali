#include <iostream>
#define TMAX 20

using namespace std;

typedef struct {
    string nome;
    float notas[4];
    float media;
} Aluno;

void lerNome(string &nome){
    cout << "Digite o nome:" << endl;
    getline(cin, nome);
}

void lerNota(float &nota){
    cout << "Digite a nota:" << endl;
    cin >> nota;
}

int main()
{
    Aluno a;
    float somaNotas = 0;

    for(int i=0; i<20; i++){
        lerNome(a.nome);
        for(int j=0; j<4; j++){
            lerNota(a.notas[j]);
            somaNotas += a.notas[j];
        }

        cout << "Nome do aluno: " << a.nome << endl;
        cout << "Média: " << somaNotas / 4;
    }
}
