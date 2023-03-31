#include <iostream>
#define TMAX 10


using namespace std;
void preencheMatrizInicial(char aM[][TMAX]);
void reproduzir(char aM[][TMAX], char bM[][TMAX]);

void preencheMatrizInicial(char aM[][TMAX]){
    for (int i=0; i<TMAX; i++)
        for (int j=0; j<TMAX; j++){
            int valorAleatorio;
                if (rand()%10 < 2 ){
                    aM[i][j] = '*';
                }
                else {
                    aM[i][j] = ' ';
                }
        }
}

void avaliaVizinhos(int i, int j, char aM[][TMAX], bM[][TMAX]){
    int cont = 0;
   for (int i=0; i<TMAX; i++){
        for (int j=0; j<TMAX; j++){

                if (aM[i-1][j-1] == '*'){
                    cont++;
                }
                if (aM[i-1][j+1] == '*'){
                    cont++;
                }
                if (aM[i-1][j] == '*'){
                    cont++;
                }
                if (aM[i][j-1] == '*'){
                    cont++;
                }
                if (aM[i+1][j+1] == '*'){
                    cont++;
                }
                if (aM[i][j+1] == '*'){
                    cont++;
                }
                if (aM[i+1][j] == '*'){
                    cont++;
                }
                if (aM[i+1][j-1] == '*'){
                    cont++;
                }
            }
        }
        reproduzir(aM, bM);
   }
}


void reproduzir(char aM[][TMAX], char bM[][TMAX]){
     if (aM[i][j] == ' '){
        if (cont == 3){
            bM[i][j] = '*';
        }
     }
}

int main()
{
    int i=0, j=0;
    char aM[TMAX][TMAX];
    char bM[TMAX][TMAX]={{' '}};

    preencheMatrizInicial(aM);

    for (int i=0; i<TMAX; i++){
        for (int j=0; j<TMAX; j++){
            cout << "[" << aM[i][j] << "]";
        }
        cout << endl;
    }

    cout << endl;
    avaliaVizinhos(aM, bM)

    for (int i=0; i<TMAX; i++){
        for (int j=0; j<TMAX; j++){
            cout << "[" << bM[i][j] << "]";
        }
        cout << endl;
    }
}

