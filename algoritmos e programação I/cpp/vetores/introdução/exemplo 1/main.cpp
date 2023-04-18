#include <iostream>

using namespace std;

int main()
{
    string nome;
    cout << "Digite seu nome completo: " << endl;
    getline(cin, nome); // O cin nesse caso, leria apenas a  primeira palavra ao invés do nome completo
    cout << nome;
}
