#include <iostream>
#define TMAX 100;

using namespace std;

typedef struct{
    int codigo;
    float salario;
    int idade;
    char sexo;
} Funcionario;

void lerFuncionarios(Funcionario &f){
    cout << "Informe o c�digo do funcion�rio: " << endl;
    cin >> f.codigo;
    cout << "Informe o sal�rio do funcion�rio: " << endl;
    cin >> f.salario;
    cout << "Informe a idade do funcion�rio: " << endl;
    cin >> f.idade;
    cout << "Informe o sexo do funcion�rio: " << endl;
    cin >> f.sexo;
}

int main()
{
    Funcionario f1;
    char opcao;

    do {
        f[i] = lerFuncionarios(f1);
    } while(opcao == 'S' and i <= TMAX);
}
