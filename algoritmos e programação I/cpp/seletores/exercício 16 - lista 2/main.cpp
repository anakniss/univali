#include <iostream>

using namespace std;

//16.  Fa�a  um  algoritmo  que  leia  o  sexo  e  altura  de  uma  pessoa  e  calcule  seu  peso  ideal,
//considerando  que  para homens o peso ideal � igual a (72,7 * altura) - 58 e para mulheres o peso ideal � igual a (62.1 * altura) - 44.7.

int main()
{
    char genero;
    float altura, pesoIdeal;

    cout << "Informe seu g�nero (com F ou M) e altura" << endl;
    cin >> genero;
    cin >> altura;

    if(genero == 'F'){
        pesoIdeal = (62.1 * altura) - 44.7;
        cout << "O seu peso ideal �: " << pesoIdeal << endl;
    }
    if(genero == 'M'){
        pesoIdeal = (72.7 * altura) - 58;
        cout << "O seu peso ideal �: " << pesoIdeal << endl;
    }
}
