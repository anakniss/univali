#include <iostream>
#define TMAX 10
#include <iomanip>

using namespace std;

void preencheMatrizInicial(char aM[][TMAX]);
int avaliaVizinhos(int i, int j, char aM[][TMAX], char bM[][TMAX]);
void reproduzir(char aM[][TMAX], char bM[][TMAX]);
void sobreviver(int i, int j, int cont, char aM[][TMAX], char bM[][TMAX]);
void morteFaltaComida(int i, int j, int cont, char aM[][TMAX], char bM[][TMAX]);
void morteSolidao(int i, int j, int cont, char aM[][TMAX], char bM[][TMAX]);


void preencheMatrizInicial(int n, char aM[][TMAX]){
    for (int i=0; i<TMAX; i++)
        for (int j=0; j < TMAX; j++){
            if (rand()%10 < 2){
                aM[i][j] = '*';
            }
            else {
                aM[i][j] = ' ';
            }
        }
}

void reproduzir(int i, int j, int cont, char aM[][TMAX], char bM[][TMAX]){
     if (aM[i][j] == ' '){
        if(cont == 3){
            bM[i][j] = '*';
        }
        else {
            bM[i][j] = ' ';
        }
     }
}

void sobreviver(int i, int j, int cont, char aM[][TMAX], char bM[][TMAX]){
    if (aM[i][j] == '*' && cont == 2 || cont == 3){
        bM[i][j] = '*';
     }
}

void morteFaltaComida(int i, int j, int cont, char aM[][TMAX], char bM[][TMAX]){
    if(aM[i][j] == '*' && cont >= 4){
        bM[i][j] = ' ';
    }
}

void morteSolidao(int i, int j, int cont, char aM[][TMAX], char bM[][TMAX]){
    if(aM[i][j] == '*' && cont == 0 || cont == 1){
        bM[i][j] = ' ';
    }
}

void mostrarMatrizes(char aM[][TMAX], char bM[][TMAX]){
    cout << "Geracao Anterior" << "                 " << "Geracao Atual" << endl;
    for (int i=0; i<TMAX; i++){
        for (int j=0; j<TMAX; j++){
            cout << "[" << aM[i][j] << "]";
        }
        cout << "   ";
        for (int j=0; j<TMAX; j++){
            cout << "[" << bM[i][j] << "]";
        }
        cout << endl;
    }
}

int avaliaVizinhos(int i, int j, char aM[][TMAX], char bM[][TMAX]){
    int cont = 0;

    if (i > 0 && j > 0 && aM[i-1][j-1] == '*'){
        cont++;
    }
    if (j > 0 && aM[i][j-1] == '*'){
        cont++;
    }
    if (i > 0 && aM[i-1][j] == '*'){
        cont++;
    }
    if (i > 0 && j+1 < TMAX && aM[i-1][j+1] == '*'){
        cont++;
    }
    if (i+1 < TMAX && j > 0 && aM[i+1][j-1] == '*'){
        cont++;
    }
    if (i+1 < TMAX && j+1 < TMAX && aM[i+1][j+1] == '*'){
        cont++;
    }
    if (j+1 < TMAX && aM[i][j+1] == '*'){
        cont++;
    }
    if (i+1 < TMAX && aM[i+1][j] == '*'){
        cont++;
    }

    return cont;
}

void transfereMatriz(char aM[][TMAX], char bM[][TMAX]){
    for (int i=0; i<TMAX; i++){
        for (int j=0; j<TMAX; j++){
            aM[i][j] = bM[i][j];
        }
    }
}

int main()
{
    srand(time(NULL));
    char aM[TMAX][TMAX];
    char bM[TMAX][TMAX];
    int cont = 0;

    preencheMatrizInicial(TMAX, aM);

    do {
        for (int i=0; i<TMAX; i++){
            for (int j=0; j<TMAX; j++){
                cont = avaliaVizinhos(i, j, aM, bM);
                reproduzir(i, j, cont, aM, bM);
                sobreviver(i, j, cont, aM, bM);
                morteFaltaComida(i, j, cont, aM, bM);
                morteSolidao(i, j, cont, aM, bM);
                }
            }


        mostrarMatrizes(aM, bM);
        cout << "Pressione ENTER para nova geracao" << endl;
        cin.ignore();

        transfereMatriz(aM, bM);

    } while(true);
}
