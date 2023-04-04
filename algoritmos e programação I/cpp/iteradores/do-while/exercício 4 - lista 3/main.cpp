#include <iostream>

using namespace std;

int main()
{
    int audiencia4 = 0;
    float porcentagem4 = 0;

    int audiencia5 = 0;
    float porcentagem5 = 0;

    int audiencia9 = 0;
    float porcentagem9 = 0;

    int audiencia12 = 0;
    float porcentagem12 = 0;

    int numeroCanal;
    char opcao;
    int totalPessoas = 0;

    do {
        int qntdPessoas = 0;

        cout << "Informe a quantidade de pessoas na casa: " << endl;
        cin >> qntdPessoas;

        cout << "Informe o número do canal: " << endl;
        cin >> numeroCanal;

        if (numeroCanal == 4){
            audiencia4 += qntdPessoas;
            totalPessoas += qntdPessoas;

            porcentagem4 = audiencia4 / totalPessoas;
        }
        else if(numeroCanal == 5){
            audiencia5 += qntdPessoas;
            totalPessoas += qntdPessoas;

            porcentagem5 = audiencia5 / totalPessoas;
        }
        else if(numeroCanal == 9){
            audiencia9 += qntdPessoas;
            totalPessoas += qntdPessoas;

            porcentagem9 = audiencia9 / totalPessoas;
        }
        else if(numeroCanal == 12){
            audiencia12 += qntdPessoas;
            totalPessoas += qntdPessoas;

            porcentagem12 = audiencia12 / totalPessoas;
        }
        else if(numeroCanal == 0){
            cout << "Não há audiência. A TV está desligada" << endl;
        }
        else {
            cout << "Número de canal inválido" << endl;
        }

        cout << "Mais uma casa? S/N " << endl;
        cin >> opcao;

    } while(opcao != 'N');

    porcentagem4 = (float) audiencia4 / totalPessoas;
    porcentagem5 = (float) audiencia5 / totalPessoas;
    porcentagem9 = (float) audiencia9 / totalPessoas;
    porcentagem12 = (float) audiencia12 / totalPessoas;

    cout << "Percentual de audiência atual do canal 4: " << endl;
    cout << porcentagem4 * 100 << "%" << endl;

    cout << "Percentual de audiência atual do canal 5: " << endl;
    cout << porcentagem5 * 100 << "%" << endl;

    cout << "Percentual de audiência atual do canal 9: " << endl;
    cout << porcentagem9 * 100 << "%" << endl;

    cout << "Percentual de audiência atual do canal 12: " << endl;
    cout << porcentagem12 * 100 << "%" << endl;
}
