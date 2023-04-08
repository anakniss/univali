#include <iostream>

using namespace std;

int main()
{
    int horas = 0;
    int qntdBiscoitos = 1;

    while(horas <= 16){
        qntdBiscoitos = qntdBiscoitos * 3;
        horas++;
    }
    cout << "Valor total após 16h: " << qntdBiscoitos << endl;
}
