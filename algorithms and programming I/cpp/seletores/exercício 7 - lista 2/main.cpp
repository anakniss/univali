#include <iostream>

using namespace std;

int main()
{
   int x, y, z;

   cout << "Informe o primeiro valor: ";
   cin >> x;

   cout << "Informe o segundo valor: ";
   cin >> y;

   cout << "Informe o terceiro valor: ";
   cin >> z;

   if (x < (y + z) || y < (x + z) || z < (x + y)){

        if (x == z && x == y) {
            cout << "Tri�ngulo equil�tero";
        }
        else if (x == z && x != y){
            cout << "Tri�ngulo is�sceles";
        }
        else if (z == y && z != x){
            cout << "Tri�ngulo is�sceles";
        }
        else if (y == x && z != y){
            cout << "Tri�ngulo is�sceles";
        }

        // Caso todos os casos acima estiverem errados, entende-se que todos os lados s�o diferentes
        else {
            cout << "Tri�ngulo escaleno";
        }
   }

   else {
    cout<< "Os valores lidos n�o formam um tri�ngulo";
   }

}
