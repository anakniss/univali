#include <iostream>

using namespace std;

int main()
{
    int codigo;
    float valor1, valor2, valor3, total;

    cout << "Informe o c�digo do item de alimenta��o: " << endl;
    cin >> codigo;

    if (codigo > 0 && codigo < 5){
        if (codigo == 1){
            valor1 = 14.50;
            cout << "C�digo: " << codigo << endl;
            cout << "Item de alimenta��o: Hamb�rguer" << endl;
            cout << valor1 << endl;
        }
        if (codigo == 2){
            valor1 = 15.50;
            cout << "C�digo: " << codigo << endl;
            cout << "Item de alimenta��o: Cheeseburguer" << endl;
            cout << valor1 << endl;
        }
        if (codigo == 3){
            valor1 = 10.0;
            cout << "C�digo: " << codigo << endl;
            cout << "Item de alimenta��o: Cachorro Quente" << endl;
            cout << valor1 << endl;
        }
        if (codigo == 4){
            valor1 = 13.50;
            cout << "C�digo: " << codigo << endl;
            cout << "Item de alimenta��o: Sandu�che Natural" << endl;
            cout << valor1 << endl;
        }
    }

    else {
        cout << "C�digo inv�lido para item de alimenta��o" << endl;
    }

    cout << "Informe o c�digo da bebida: " << endl;
    cin >> codigo;

    if (codigo > 4 && codigo < 7){
        if (codigo == 5){
            valor2 = 5;
            cout << "C�digo: " << codigo << endl;
            cout << "Item de alimenta��o: Refrigerante" << endl;
            cout << valor2 << endl;
        }
        if (codigo == 6){
            valor2 = 6;
            cout << "C�digo: " << codigo << endl;
            cout << "Item de alimenta��o: Suco de Laranja" << endl;
            cout << valor2 << endl;
        }
    }

     else {
        cout << "C�digo inv�lido para bebida" << endl;
    }

    cout << "Informe o c�digo da sobremesa: " << endl;
    cin >> codigo;

    if (codigo > 6 && codigo < 10){
        if (codigo == 7){
            valor3 = 10.50;
            cout << "C�digo: " << codigo << endl;
            cout << "Item de alimenta��o: Milkshake" << endl;
            cout << valor3 << endl;
        }
        if (codigo == 8){
            valor3 = 13;
            cout << "C�digo: " << codigo << endl;
            cout << "Item de alimenta��o: Sundae" << endl;
            cout << valor3 << endl;
        }
            if (codigo == 9){
            valor3 = 10;
            cout << "C�digo: " << codigo << endl;
            cout << "Item de alimenta��o: Casquinha" << endl;
            cout << valor3 << endl;
        }
    }

     else {
        cout << "C�digo inv�lido para sobremesa" << endl;
    }

    total = valor1 + valor2 + valor3;

    cout << "Valor total: " << total;
}
