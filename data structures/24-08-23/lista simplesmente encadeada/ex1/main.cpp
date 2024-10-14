#include <iostream>

using namespace std;

int main()
{
    ListaSimplesmenteEncadeada<int> lista1;
    ListaSimplesmenteEncadeada<char> lista2;

    cria(lista1);
    cria(lista2);

    destroi(lista1);
    destroi(lista2);

    return 0;
}
