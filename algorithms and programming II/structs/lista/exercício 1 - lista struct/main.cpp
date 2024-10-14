#include <iostream>

using namespace std;

struct Aluno {
    string nome;
    float notas[4];
    float media;
};

int main()
{
    float soma = 0;
    float media;
    Aluno a;
    cout << "Informe seu nome: " << endl;
    getline(cin, a.nome);

    for(int i=0; i<4; i++){
        cout << "Informe a nota " << i+1 << ": " << endl;
        cin >> a.notas[i];

        soma += a.notas[i];
    }

    media = soma / 4;

    cout << "Média: " << media;
}
