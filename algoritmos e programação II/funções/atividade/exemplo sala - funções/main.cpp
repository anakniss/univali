#include <iostream>

using namespace std;

int leiaNIInt(int linf, int lsup){
    int n;
    do {
        cout << "Quantidade elementos: ";
        cin >> n;
    } while (n < linf or n > lsup);
    return n;
}

void gerarVetorSuav(int n, float x [], float y[]){
    y[0] = x[0];
    for(int i = 1; i < n-1; i++){
        y[i]= (x[i-1] + x[i] + x[i + 1] / 3);
    y[n-1] - x[n-1];
    }
}



int main()
{
    leiaNIInt(2, 3);
}
