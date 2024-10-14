#include <iostream>

using namespace std;

int leiaNumInteiroIntervalo(int linf, int lsup){
    int n;
    do {
        cout << "Quantidade de elementos: (" << linf << "-" << lsup << "):";
        cin(n);
    } while(n >= linf && n <= lsup);

    return n;
}

void lerMatriz(int n1, nc, int mA[][10]){
    int i, j;
    for(i = 0; i < n1, i++){
        for(j = 0; j < nc; j++){
            cout << "Elemento: " << i << j << endl;
            cin >> mA[i, j];
        }
    }
}

int main()
{
    int n;
    int linf, lsup;
}
