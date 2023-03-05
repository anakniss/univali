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
            cout << "Triângulo equilátero";
        }
        else if (x == z && x != y){
            cout << "Triângulo isósceles";
        }
        else if (z == y && z != x){
            cout << "Triângulo isósceles";
        }
        else if (y == x && z != y){
            cout << "Triângulo isósceles";
        }

        // Caso todos os casos acima estiverem errados, entende-se que todos os lados são diferentes
        else {
            cout << "Triângulo escaleno";
        }
   }

   else {
    cout<< "Os valores lidos não formam um triângulo";
   }

}
