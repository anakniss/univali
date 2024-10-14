#include <iostream>

using namespace std;

int main()
{
    float salario, aumento;

    cout << "Informe seu salário: ";
    cin >> salario;

    if (salario <= 400) {
        salario += salario * 0.15;
        cout << "Você obteve um aumento de 15%. Seu salário atual é de: " << salario;
    }

    else if ((salario > 400) && (salario <= 700)){
        salario += salario * 0.12;
        cout << "Você obteve um aumento de 12%. Seu salário atual é de: " << salario;
    }

    else if ((salario > 700) && (salario <= 1000)){
        salario += salario * 0.10;
        cout << "Você obteve um aumento de 10%. Seu salário atual é de: " << salario;
    }

    else if ((salario > 1000) && (salario <= 1500)){
        salario += salario * 0.07;
        cout << "Você obteve um aumento de 7%. Seu salário atual é de: " << salario;
    }

    else if ((salario > 1500) && (salario <= 2000)){
        salario += salario * 0.04;
        cout << "Você obteve um aumento de 7%. Seu salário atual é de: " << salario;
    }
    else {
        cout << "Sem aumento";
    }
}
