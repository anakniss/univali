#include <iostream>

using namespace std;

int main()
{
    string nome;
    char categoria;
    float salario;

    cout << "Informe seu nome: " << endl;
    cin >> nome;

    cout << "Informe a sua categoria: " << endl;
    cin >> categoria;

    cout <<"Informe seu salário: " << endl;
    cin >> salario;

    cout << "Nome: " << nome << endl;

    if(char(categoria) == 65 || char(categoria) == 67 || char(categoria) == 70 || char(categoria) == 72){
        salario = salario + (salario * 0.10);
        cout << "Salário: " << salario << endl;
    }
    if(char(categoria) == 66 || char(categoria) == 68 || char(categoria) == 69 || char(categoria) == 71){
        salario = salario + (salario * 0.15);
        cout << "Salário: " << salario << endl;
    }
    if(char(categoria) == 73 || char(categoria) >= 75 && char(categoria) <= 82){
        salario = salario + (salario * 0.20);
        cout << "Salário: " << salario << endl;
    }
    if(char(categoria) == 74 || char(categoria) >= 83 && char(categoria) <= 90){
        salario = salario + (salario * 0.25);
        cout << "Salário: " << salario << endl;
    }
}
