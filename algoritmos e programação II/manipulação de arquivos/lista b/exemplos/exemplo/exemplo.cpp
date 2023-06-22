#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ofstream arq;
    arq.open("arquivo.txt", ios::binary | ios::out);

    if (arq.is_open()) 
    {
        //grava o valor x no arquivo
        cout << "Definindo e salvando informação no arquivo binario..." << endl;
        float x = 5;
        cout << "Informação salva: " << x << endl;
        arq.write((const char*)(&x), sizeof(x));

        //grava todo o array no arquivo
        cout << "Definindo e salvando informação no arquivo binario..." << endl;
        int a[5] = { 1, 2, 3, 4, 5 };
        cout << "Informação salva: ";
        for (int i = 0; i < 5; i++) {
            cout << a[i] << " ";
        }
        arq.write((const char*)a, 5*sizeof(a));

        arq.close();
    }
}

