#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ofstream arquivo;

    //o comando ios::app permite a não sobrescrever a informação já adicionada no arquivo

    arquivo.open("exemplo_ofstream.txt", ios::app);

    arquivo << "Nome\n";
    arquivo << "Ana Clara Kniss";

    arquivo.close();

    return 0;
}
