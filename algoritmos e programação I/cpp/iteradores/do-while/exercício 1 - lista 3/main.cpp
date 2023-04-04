#include <iostream>

using namespace std;

int main()
{
    int num, i = 0;
    float media = 0;

    do {
        cout << "Informe números pares: " << endl;
        cin >> num;

        if(num % 2 == 0 && num != 0){
            media = num + media;
            i++;
        }
        else {
            cout << "Informe apenas números pares!" << endl;
        }
    } while(num != 0);

    cout << "A média dos valores informados é: " << (media) / i;
}
