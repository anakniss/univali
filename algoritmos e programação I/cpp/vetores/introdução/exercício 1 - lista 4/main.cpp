#include <iostream>

using namespace std;

int main()
{
    int n;
    float media;
    int abaixoMedia = 0;
    string nomes[20];
    float notas[20];

    cout << "Informe a quantidade de estudantes (máx 20): " << endl;
    cin >> n;

    float soma = 0;

    for(int i=0; i>=0 and i<n; i++){
        cin.ignore();
        cout << "Digite o nome do estudante " << i+1 << ": " << endl;
        getline(cin, nomes[i]);

        cout << "Digite a nota do estudante " << i+1 << ": " << endl;
        cin >> notas[i];

        soma += notas[i];
    }

    media = soma/n;

    for(int i=0; i<n; i++){
        if(notas[i] >= media){
            cout << "Nome aluno acima da média: " << nomes[i] << endl;
        }
    }

    for(int i=0; i<n; i++){
        if(notas[i] < media){
            abaixoMedia++;
        }
    }

    cout << "Quantidade de estudantes com notas abaixo da média: " << abaixoMedia << endl;
}
