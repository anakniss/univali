#include <iostream>

using namespace std;

int maioresN (int n, int tamanho, int vet[]){
    if(tamanho == 0)
        return 0;
    cout << tamanho - 1 << " " << vet[tamanho - 1] << endl;
    if(vet[tamanho - 1] > n){
        return 1 + maioresN(n, tamanho - 1, vet);
    }
    else {
        return maioresN(n, tamanho - 1, vet);
    }
}

int main()
{
    int vet[] = {1, 2, 3, 4, 5, 6}, n = 4, tamanho = 6;

    cout <<  "Qntd elementos > 4 no vetor: " << maioresN(n, tamanho, vet);

    return 0;
}
