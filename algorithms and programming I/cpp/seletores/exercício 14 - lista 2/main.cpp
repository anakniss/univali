#include <iostream>

using namespace std;

int main()
{
    int codigo;
    float valor1, valor2, valor3, total;

    cout << "Informe o código do item de alimentação: " << endl;
    cin >> codigo;

    if (codigo > 0 && codigo < 5){
        if (codigo == 1){
            valor1 = 14.50;
            cout << "Código: " << codigo << endl;
            cout << "Item de alimentação: Hambúrguer" << endl;
            cout << valor1 << endl;
        }
        if (codigo == 2){
            valor1 = 15.50;
            cout << "Código: " << codigo << endl;
            cout << "Item de alimentação: Cheeseburguer" << endl;
            cout << valor1 << endl;
        }
        if (codigo == 3){
            valor1 = 10.0;
            cout << "Código: " << codigo << endl;
            cout << "Item de alimentação: Cachorro Quente" << endl;
            cout << valor1 << endl;
        }
        if (codigo == 4){
            valor1 = 13.50;
            cout << "Código: " << codigo << endl;
            cout << "Item de alimentação: Sanduíche Natural" << endl;
            cout << valor1 << endl;
        }
    }

    else {
        cout << "Código inválido para item de alimentação" << endl;
    }

    cout << "Informe o código da bebida: " << endl;
    cin >> codigo;

    if (codigo > 4 && codigo < 7){
        if (codigo == 5){
            valor2 = 5;
            cout << "Código: " << codigo << endl;
            cout << "Item de alimentação: Refrigerante" << endl;
            cout << valor2 << endl;
        }
        if (codigo == 6){
            valor2 = 6;
            cout << "Código: " << codigo << endl;
            cout << "Item de alimentação: Suco de Laranja" << endl;
            cout << valor2 << endl;
        }
    }

     else {
        cout << "Código inválido para bebida" << endl;
    }

    cout << "Informe o código da sobremesa: " << endl;
    cin >> codigo;

    if (codigo > 6 && codigo < 10){
        if (codigo == 7){
            valor3 = 10.50;
            cout << "Código: " << codigo << endl;
            cout << "Item de alimentação: Milkshake" << endl;
            cout << valor3 << endl;
        }
        if (codigo == 8){
            valor3 = 13;
            cout << "Código: " << codigo << endl;
            cout << "Item de alimentação: Sundae" << endl;
            cout << valor3 << endl;
        }
            if (codigo == 9){
            valor3 = 10;
            cout << "Código: " << codigo << endl;
            cout << "Item de alimentação: Casquinha" << endl;
            cout << valor3 << endl;
        }
    }

     else {
        cout << "Código inválido para sobremesa" << endl;
    }

    total = valor1 + valor2 + valor3;

    cout << "Valor total: " << total;
}
