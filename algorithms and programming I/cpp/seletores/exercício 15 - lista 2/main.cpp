#include <iostream>

using namespace std;

int main()
{
    char opcao;
    float base, altura, area;

    cout << "Informe a op��o desejada: \n T- Calcular �rea de um tri�ngulo \n Q- Calcular �rea de um quadrado \n R- Calcular �rea de um ret�ngulo" << endl;
    cin >> opcao;

    if(opcao == 'T'){
        cout << "Voc� escolheu a op��o T. � necess�rio que nos informe a base e a altura do tri�ngulo." << endl;
        cin >> base;
        cin >> altura;

        area = base * altura;

        cout << "A �rea do tri�ngulo � de: " << area << endl;
    }
    else if (opcao == 'Q'){
        cout << "Voc� escolheu a op��o Q. � necess�rio que nos informe o valor de um dos lados do quadrado" << endl;
        cin >> base;

        area = base * base;

        cout << "A �rea do quadrado � de: " << area << endl;
    }
    else if (opcao == 'R'){
        cout << "Voc� escolheu a op��o R. � necess�rio que nos informe o valor da base e a altura" << endl;
        cin >> base;
        cin >> altura;

        area = base * altura;

        cout << "A �rea do ret�ngulo � de: " << area << endl;
    }
}
