#include <iostream>

using namespace std;

//Faça um algoritmo que leia n pares de valores, sendo o primeiro valor o número de inscrição do atleta e o segundo a altura
//(em cm) do atleta. Escreva:    o número de inscrição e a altura do atleta mais alto;    o número de inscrição e a altura
//do atleta mais baixo;    a altura média do grupo de atletas.

int main()
{
    int i, qntd;
    float insc, inscAlto = 0, inscBaixo = 0, altura, alturaAlto = 0, alturaBaixo = 100, alturaMedia = 0;

    cout << "Informe a quantidade de atletas a serem verificados: " << endl;
    cin >> qntd;

    for(i=0; i<qntd; i++){
        cout << "Informe o número de inscrição do atleta: " << endl;
        cin >> insc;

        cout << "Informe a altura do atleta: " << endl;
        cin >> altura;

        if(altura >= alturaAlto){
            alturaAlto = altura;
            inscAlto = insc;
        }

        if(altura < alturaBaixo){
            alturaBaixo = altura;
            inscBaixo = insc;
        }

        alturaMedia += altura;
    }

    cout << "Inscrição e altura do atleta mais alto: " << inscAlto << ", " << alturaAlto << endl;
    cout << "Inscrição e altura do atleta mais baixo: " << inscBaixo << ", " << alturaBaixo << endl;
    cout << "Média da altura dos atletas: " << alturaMedia / float(qntd);

}
