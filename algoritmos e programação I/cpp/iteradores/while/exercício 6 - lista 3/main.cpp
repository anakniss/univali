#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    int horas = 0;
    int qntdBiscoitos = 0;
    int qntdBiscoitosTotal = 0;

    while(horas < 3){
        qntdBiscoitos = pow(3, horas);
        qntdBiscoitosTotal = qntdBiscoitos + qntdBiscoitosTotal;
        horas++;
    }
    cout << "Valor total após 16h: " << qntdBiscoitosTotal << endl;
}
