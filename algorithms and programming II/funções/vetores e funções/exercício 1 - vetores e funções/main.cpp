#include <iostream>
#define TMAX 20

using namespace std;

int lerQuantidadeAlunos(){
    int n;

    do {
        cout << "Informe o tamanho da turma: ";
        cin >> n;
    } while(n > TMAX);

    return n;
}

void lerAlunos(string nomes[], float notas[], int n){
    int i = 0;
    for(i=0; i < n; i++){
        cout << "Informe o nome do aluno: ";
        cin >> nomes[i];

        cout << "Informe a nota do aluno: ";
        cin >> notas[i];
    }
}

float calcularMedia(float notas[], int n){
    float soma = 0;
    int i = 0;
    for(i=0; i < n; i++){
        soma += notas[i];
    }
    return soma / n;
}

void acimaMedia(string nomes[], float media, float notas[], int n){
    int i = 0;
    for(i=0; i<n; i++){
        if(notas[i] >= media){
            cout << "Aluno acima da média: " << nomes[i] << endl;
        }
    }
}

void menorMedia(float media, float notas[], int n){
    int i = 0;
    int cont = 0;
    for(i=0; i<n; i++){
        if(notas[i] <= media){
            cont++;
        }
    }
    cout << "Quantidade de alunos abaixo da média: " << cont;
}


int main()
{
    int n = lerQuantidadeAlunos();
    string nomes[n];
    float notas[n];

    lerAlunos(nomes, notas, n);

    float media = calcularMedia(notas, n);
    cout << media << endl;
    acimaMedia(nomes, media, notas, n);
    menorMedia(media, notas, n);
}
