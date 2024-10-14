#include <iostream>
#define TMAX 100

using namespace std;

int main()
{
    int n;
    int insc[TMAX];
    float alturas[TMAX];
    int inscMenor, inscMaior;
    float menor, maior, media = 0;

    do {
        cout << "Informe a quantidade de atletas a serem lidos: " << endl;
        cin >> n;
    } while(n < 0 or n > 100);

    for(int i=0; i<n; i++){
        cout << "Informe o número de inscrição do atleta: ";
        cin >> insc[i];

        cout << "Informe o número de altura do atleta: ";
        cin >> alturas[i];

        media += alturas[i];
    }

    maior = alturas[0];
    inscMaior = insc[0];
    menor = alturas[0];
    inscMenor = insc[0];

    for(int i=1; i<n; i++){
        if(alturas[i] > maior){
            maior = alturas[i];
            inscMaior = insc[i];
        }
        else if (alturas[i] < menor){
            menor = alturas[i];
            inscMenor = insc[i];
        }
    }

    cout << "Altura do atleta maior: " << maior << endl;
    cout << "Inscrição do atleta maior: " << inscMaior << endl;
    cout << "Altura do atleta menor: " << menor << endl;
    cout << "Inscrição do atleta menor: " << inscMenor << endl;
    cout << "Média das alturas: " << media / float(n) << endl;

}
