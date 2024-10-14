#include <iostream>

using namespace std;

int main () {
    string nome;
    float horasExtras, horasTotais;
    int faltas;

    cout << "Informe seu nome: \n";
    cin >> nome;
    cout << "Informe a quantidade de horas extras trabalhadas: \n";
    cin >> horasExtras;
    cout << "Informe a quantidade de horas das faltas: \n";
    cin >> faltas;

    horasTotais = horasExtras - (faltas * 2.0) / 3.0;

    if (horasTotais > 40) {
        cout << "Você receberá R$1000,00 de gratificação!";
        cout << horasTotais;
    }
    else if (horasTotais >= 30 && horasTotais <= 40){
        cout << "Você receberá R$800,00 de gratificação!";
        cout << horasTotais;
    }
    else if (horasTotais >= 20 && horasTotais <= 30 ) {
        cout << "Você receberá R$600,00 de gratificação!";
        cout << horasTotais;
    }
    else if (horasTotais >= 10 && horasTotais <= 20 ) {
        cout << "Você receberá R$400,00 de gratificação!";
        cout << horasTotais;
    }
    else if (horasTotais <= 10) {
        cout << "Você receberá R$200,00 de gratificação!";
        cout << horasTotais;
    }
}