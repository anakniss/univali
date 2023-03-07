#include <iostream>

using namespace std;

int main()
{
    float indicePoluicao;
    cout << "Informe o índice de poluição: " << endl;
    cin  >> indicePoluicao;

    if (indicePoluicao >= 0.0 && indicePoluicao < 0.30) {
        cout << "Índice de poluição regular" << endl;
    }

    else if (indicePoluicao >= 0.30) {
        cout << "Lista A" << endl;

        if (indicePoluicao < 0.40) {
        cout << "Aviso de suspensão das atividades até diminuir os valores do índice de poluição" << endl;
        }

        if (indicePoluicao >= 0.40 && indicePoluicao < 0.50){
            cout << "Lista B" << endl;
            cout << "Aviso de suspensão das atividades até diminuir os valores do índice de poluição" << endl;
        }

        else {
            cout << "Lista C" << endl;
            cout << "Aviso de suspensão das atividades" << endl;
        }
    }
}
