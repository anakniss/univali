#include <iostream>
#include <math.h>
#include <cmath>

using namespace std;

int main()
{
    float a, b, c, d;

    cout<< "Informe o valor de a: ";
    cin >> a;

    cout<< "Informe o valor de b: ";
    cin >> b;

    cout<< "Informe o valor de c: ";
    cin >> c;

    d = pow(b, 2) - (4 * a * c);

    if (d == 0){
        cout << "Raiz real";
    }
    else if (d > 0){
        cout << "Raízes distintas";
    }
    else {
        cout << "Nenhuma raiz";
    }

}
