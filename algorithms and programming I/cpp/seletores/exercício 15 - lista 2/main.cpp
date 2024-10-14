#include <iostream>

using namespace std;

int main()
{
    char opcao;
    float base, altura, area;

    cout << "Informe a opção desejada: \n T- Calcular área de um triângulo \n Q- Calcular área de um quadrado \n R- Calcular área de um retângulo" << endl;
    cin >> opcao;

    if(opcao == 'T'){
        cout << "Você escolheu a opção T. É necessário que nos informe a base e a altura do triângulo." << endl;
        cin >> base;
        cin >> altura;

        area = base * altura;

        cout << "A área do triângulo é de: " << area << endl;
    }
    else if (opcao == 'Q'){
        cout << "Você escolheu a opção Q. É necessário que nos informe o valor de um dos lados do quadrado" << endl;
        cin >> base;

        area = base * base;

        cout << "A área do quadrado é de: " << area << endl;
    }
    else if (opcao == 'R'){
        cout << "Você escolheu a opção R. É necessário que nos informe o valor da base e a altura" << endl;
        cin >> base;
        cin >> altura;

        area = base * altura;

        cout << "A área do retângulo é de: " << area << endl;
    }
}
