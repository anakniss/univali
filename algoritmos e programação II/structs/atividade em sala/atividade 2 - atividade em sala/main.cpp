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
    cout << "Informe o código do funcionário: " << endl;
    cin >> f.codigo;
    cout << "Informe o salário do funcionário: " << endl;
    cin >> f.salario;
    cout << "Informe a idade do funcionário: " << endl;
    cin >> f.idade;
    cout << "Informe o sexo do funcionário: " << endl;
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
