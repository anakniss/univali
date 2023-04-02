#include <iostream>
#define TMAX 10

using namespace std;

void preencheMatrizInicial(char aM[][TMAX]);
void reproduzir(char aM[][TMAX], char bM[][TMAX]);
void avaliaVizinhos(int i, int j, char aM[][TMAX], char bM[][TMAX]);

void preencheMatrizInicial(int n, char aM[][TMAX]){
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++){
            int valorAleatorio;
                if (rand()%10 < 2 ){
                    aM[i][j] = '*';
                }
                else {
                    aM[i][j] = ' ';
                }
        }
}

void reproduzir(int i, int j, int cont, char aM[][TMAX], char bM[][TMAX]){
     if (aM[i][j] == ' '){
        if (cont == 4){
            bM[i][j] = '*';
        }
     }
}



void avaliaVizinhos(int i, int j, char aM[][TMAX], char bM[][TMAX]){
    int cont=0;
                if (aM[i-1][j-1] == '*'){
                    cont++;
                }
                if (aM[i-1][j] == '*'){
                    cont++;
                }
                if (aM[i-1][j+1] == '*'){
                    cont++;
                }
                if (aM[i+1][j-1] == '*'){
                    cont++;
                }
                if (aM[i+1][j+1] == '*'){
                    cont++;
                }
                if (aM[i][j+1] == '*'){
                    cont++;
                }
                if (aM[i+1][j-1] == '*'){
                    cont++;
                }
                if (aM[i+1][j] == '*'){
                    cont++;
                }

    reproduzir(i, j, cont, aM, bM);
    cont =0;
}

int main()
{
    int n=10, cont=0;
    char aM[TMAX][TMAX];
    char bM[TMAX][TMAX]={{' '}};

    preencheMatrizInicial(n, aM);

    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            cout << "[" << aM[i][j] << "]";
        }
        cout << endl;
    }

    cout << endl;
    for (int i=0; i<n; i++)
       for (int j=0; j<n; j++)
            avaliaVizinhos(i, j, aM, bM);


    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            cout << "[" << bM[i][j] << "]";
        }
        cout << endl;
    }
}
