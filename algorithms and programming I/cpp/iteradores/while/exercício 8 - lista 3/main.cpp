#include <iostream>

using namespace std;

int main()
{
    float massaInicial, massaFinal;
    int segundos = 0;

    cout << "Informe a massa inicial (em Kg): " << endl;
    cin >> massaInicial;

    cout << "Massa inicial: " << massaInicial << endl;

    while(massaInicial > 0.5){
        segundos += 50;
        massaInicial = massaInicial / 2;
        massaFinal = massaInicial;
    }

    cout << "Massa final: " << massaFinal << endl;
    cout << "Segundos: " << segundos << endl;

}
