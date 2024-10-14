#include <iostream>
#define TMAX 20

using namespace std;

int main()
{
    int n;
    float media;
    int abaixoMedia = 0;
    string nomes[TMAX];
    float notas[TMAX];

    do {
        cout << "Informe a quantidade de estudantes (m�x 20): " << endl;
        cin >> n;

        if(n < 0 || n > TMAX){
            cout << "Informe um n�mero v�lido" << endl;
        }

    } while(n < 0 || n > TMAX);

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
            cout << "Nome aluno acima da m�dia: " << nomes[i] << endl;
        }
        else {
            abaixoMedia++;
        }
    }

    cout << "Quantidade de estudantes com notas abaixo da m�dia: " << abaixoMedia << endl;
}
