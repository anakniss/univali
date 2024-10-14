#include <iostream>

using namespace std;

int main()
{
    int num = 1;
    int num1;
    float media;
    int ind = 0;

    do {
       cout << "Informe números pares: ";
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
    cout << "A média dos números informados é de: " << num1 << endl;
}
