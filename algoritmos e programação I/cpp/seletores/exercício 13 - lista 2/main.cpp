#include <iostream>

using namespace std;

int main()
{
    float indicePoluicao;
    cout << "Informe o �ndice de polui��o: " << endl;
    cin  >> indicePoluicao;

    if (indicePoluicao >= 0.0 && indicePoluicao < 0.30) {
        cout << "�ndice de polui��o regular" << endl;
    }
    else if (indicePoluicao >= 0.30 && indicePoluicao < 0.40 ) {
        cout << "Lista A" << endl;
        cout << "Aviso de suspens�o das atividades at� diminuir os valores do �ndice de polui��o" << endl;
    }
    else if (indicePoluicao >= 0.40 && indicePoluicao < 0.50){
        cout << "Lista A" << endl;
        cout << "Lista B" << endl;
        cout << "Aviso de suspens�o das atividades at� diminuir os valores do �ndice de polui��o" << endl;
    }
    else if (indicePoluicao >= 0.50) {
        cout << "Lista A" << endl;
        cout << "Lista B" << endl;
        cout << "Lista C" << endl;
        cout << "Aviso de suspens�o das atividades" << endl;
    }
}
