#include <iostream>

using namespace std;

int main()
{
    int horas = 0;
    int qntdBiscoitos = 0;
    int valorAnterior = 3, valorAtual = 3;

    while(horas < 16){
        cout << "Valor anterior: " << valorAnterior << endl;
        valorAtual = valorAtual * valorAnterior;
        valorAnterior = valorAtual;
        cout << "Valor atual: " << valorAtual << endl;
        horas++;
    }
    cout << "Valor total após 16h: " << valorAtual << endl;

}
