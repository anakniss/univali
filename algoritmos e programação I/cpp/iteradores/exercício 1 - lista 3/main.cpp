#include <iostream>

using namespace std;

int main()
{
    int num, i = 0;
    float media = 0;

    do {
        cout << "Informe n�meros pares: " << endl;
        cin >> num;

        if(num % 2 == 0 && num != 0){
            media = num + media;
            i++;
        }
        else {
            cout << "Informe apenas n�meros pares!" << endl;
        }
    } while(num != 0);

    cout << "A m�dia dos valores informados �: " << (media) / i;
}
