#include <iostream>

using namespace std;

int main()
{
    int horas = 1;
    int qntdBiscoitos = 1;
    int qntdBiscoitosTotal = 1;

    while(horas < 16){
        qntdBiscoitos = qntdBiscoitos * 3;
        qntdBiscoitosTotal = qntdBiscoitos + qntdBiscoitosTotal;
        horas++;
    }
    cout << "Valor total após 16h: " << qntdBiscoitosTotal << endl;
}
