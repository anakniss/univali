#include <iostream>

using namespace std;

int main()
{
    int codigo, quantidadeItens, quantidadeCombo;
    float valor, resto;

    cout << "Informe o código do pedido que deseja: " << endl;
    cin >> codigo;
    cout << "Informe a quantidade de itens" << endl;
    cin >> quantidadeItens;

    resto = quantidadeItens % 5;
    quantidadeCombo = int(quantidadeItens / 5);

    if (codigo == 100){
        valor = (quantidadeItens * 13) - (quantidadeCombo * 13);
        cout << "O valor total da promoção é: " << valor << endl;

        cout << "Resto: " << resto << endl;
    }
    else if (codigo == 101){
        valor = (quantidadeItens * 12.50) - (quantidadeCombo * 12.50);
        cout << "O valor total da promoção é: " << valor << endl;

        cout << "Resto: " << resto << endl;
    }
    else if (codigo == 102){
        valor = (quantidadeItens * 12) - (quantidadeCombo * 12);
        cout << "O valor total da promoção é: " << valor << endl;

        cout << "Resto: " << resto << endl;
    }
    else if (codigo == 103){
        valor = (quantidadeItens * 12.25) - (quantidadeCombo * 12.25);
        cout << "O valor total da promoção é: " << valor << endl;

        cout << "Resto: " << resto << endl;
    }
    else {
        cout << "Informe um código válido";
    }
}
