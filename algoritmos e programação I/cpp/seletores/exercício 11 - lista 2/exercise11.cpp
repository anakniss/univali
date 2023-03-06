#include <iostream>

using namespace std;

int main(){
    int horasInicio, horasFim, duracao;

    cout << "Informe o horário do início do jogo: ";
    cin >> horasInicio;

    cout << "Informe o horário do fim do jogo: ";
    cin >> horasFim;

    if (horasInicio >= 0 && horasInicio <= 24 && horasFim >= 0 && horasFim <= 24) {
        if(horasInicio > horasFim){
            duracao = 24 - (horasInicio + horasFim);
            cout << "A duração do jogo foi de: " << duracao;
        }
        else if (horasInicio < horasFim){
            duracao = horasFim - horasInicio;
            cout << "A duração do jogo foi de: " << duracao;
        }
        else {
            cout << "Não houveram horas de duração";
        }
    }
    else {
        cout << "Informe um horário válido";
    }
}