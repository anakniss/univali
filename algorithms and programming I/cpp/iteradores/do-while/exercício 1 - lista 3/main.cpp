#include <iostream>

using namespace std;

int main()
{
    int num = 1;
    int num1;
    float media;
    int ind = 0;

    do {
       cout << "Informe n�meros pares: ";
       cin >> num;

       if(num % 2 == 0){
        num1 = num + num1;
        ind = ind++;
       }
       else {
        cout << "Informe um valor par!";
       }
    } while (num != 0);

    media = num1 / ind;
    cout << "A m�dia dos n�meros informados � de: " << num1 << endl;
}
