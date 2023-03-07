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
    else if (indicePoluicao >= 0.30 && indicePoluicao < 0.40 ) {
        cout << "Lista A" << endl;
        cout << "Aviso de suspensão das atividades até diminuir os valores do índice de poluição" << endl;
    }
    else if (indicePoluicao >= 0.40 && indicePoluicao < 0.50){
        cout << "Lista A" << endl;
        cout << "Lista B" << endl;
        cout << "Aviso de suspensão das atividades até diminuir os valores do índice de poluição" << endl;
    }
    else if (indicePoluicao >= 0.50) {
        cout << "Lista A" << endl;
        cout << "Lista B" << endl;
        cout << "Lista C" << endl;
        cout << "Aviso de suspensão das atividades" << endl;
    }
}
