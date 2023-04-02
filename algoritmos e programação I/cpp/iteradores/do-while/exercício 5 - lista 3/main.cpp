#include <iostream>

using namespace std;

int main()
{
    int cont = 0;
    float valorProduto = 0;
    float totalVendas = 0;
    float salarioVendedor = 0;
    char opcao;
    string nome;

    do {
        cout << "Informe o nome do funcionário: " << endl;
        cin >> nome;
        do {
            cout << "Informe o valor do produto vendido: " << endl;
            cin >> valorProduto;

            cout << "Informe a quantidade vendida:" << endl;
            cin >> cont;


            salarioVendedor += (valorProduto * 0.3) * cont;


            totalVendas += valorProduto * cont;

            cout << "Este funcionário tem mais uma venda? S/N" << endl;
            cin >> opcao;

        } while(opcao == 'S');

        cout << "Nome do vendedor: " << nome << endl;
        cout << "Total de vendas: R$" << totalVendas << endl;
        cout << "Salário do vendedor: R$" << salarioVendedor << endl;

        cout << "Deseja digitar os dados de mais um vendedor? S/N" << endl;
        cin >> opcao;
    } while(opcao == 'S');
}
