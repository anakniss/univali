#include <iostream>

using namespace std;

typedef struct{
    string nome;
    float notas[4], media;
} Aluno;

int leiaNLimSup();
void leiaTurma(int, Aluno[]);
void gerarMediaAluno(int, Aluno[]);
float gerarMediaTurma(int, Aluno[]);
void relatorioMF(int, Aluno[]);

int main(){
    Aluno *vetDinam = NULL;
    int n = leiaNLimSup();
    vetDinam = new Aluno[n];
    leiaTurma(n, turma);
    gerarMediaAluno(n, turma);
    relatorioMF(n, turma);
    return 0;
}

int leiaNLimSup(){
    int n;
    do{
        cout << "Qtd desejada: ";
        cin >> n;
    }while(n<=0 or n>lsup);
    return n;
}

void leiaTurma(int n, Aluno t[]){
    for(int i=0; i<n; i++){
        cin.ignore();
        cout << "Nome"; getline(cin, t[i].nome);
        for (int j=0; j<4; j++){
            cout << j+1 << "a nota: "; cin >> t[i].notas[j];
        }
        t[i].media  = 0;
    }
}

void gerarMediaAluno(int n, Aluno t[]){
    for(int i=0; i<n; i++){
        t[i].media  = 0;
        for (int j=0; j<4; j++){
            t[i].media += t[i].notas[j];
        }
        t[i].media = t[i].media/4;
    }
}

float gerarMediaTurma(int n, Aluno t[]){
    float mediaT=0;
    for (int i=0; i<n; i++){
        mediaT += t[i].media;
    }
    return mediaT/n;
}

void relatorioMF(int n, Aluno t[]){
    int cont = 0;
    float x = gerarMediaTurma(n, t);
    cout << "Relatorio MF" << endl;
    for(int i=0; i<n; i++){
        cout << t[i].nome << " " << t[i].media << endl;
        if(t[i].media<x) cont++;
    }
    cout << "Media da turma: " << x << endl;
    cout << "Qtd alunos abaixo da media: " << cont << endl;
}
