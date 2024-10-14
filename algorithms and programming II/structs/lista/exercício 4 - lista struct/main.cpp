#include <iostream>
#include <iomanip>

using namespace std;

typedef struct {
    string matricula;
    string nome;
    string cargo;
    string departamento;
    string dataAdm;
    float salario;
} Funcionario;

char leiaCaracter();
void leiaFuncionario(int, Funcionario[]);
void mostraFuncionario(Funcionario);
void relatorio(int, Funcionario[]);
float calculaMedia(int, Funcionario[]);

char leiaCaracter(){
    char opcao;
    do {
        cout << "Outro funcionario? S/N" << endl;
        opcao = toupper(cin.get());
    } while(opcao != 'S' and opcao != 'N');
    cin.ignore();
    return opcao;
}

void leiaFuncionario(int i, Funcionario f[]){
    cout << "Dados do funcionario" << endl;
    cout << "Nome: " << endl;
    getline(cin, f[i].nome);
    cout << "Matricula" << endl;
    getline(cin, f[i].matricula);
    cout << "Cargo: " << endl;
    getline(cin, f[i].cargo);
    cout << "Departamento: " << endl;
    getline(cin, f[i].departamento);
    cout << "Data: " << endl;
    getline(cin, f[i].dataAdm);
    do {
        cout << "Salario: " << endl;
        cin >> f[i].salario;
    } while(f[i].salario <= 0);
    cin.ignore();
}

void mostraFuncionario(Funcionario f){
    cout << "Nome: " << f.nome << ", " <<  f.cargo << " - " << f.salario << endl;
}

float calculaMedia(int n, Funcionario f[]){
    float media = 0;
    for (int i=0; i<n; i++){
        media += f[i].salario;
    }
    return media/n;
}

void relatorio(int n, Funcionario f[]){
    float media = calculaMedia(n, f);
    cout << fixed << setprecision(2) << endl;
    cout << "Relatorio - Salarios acima da media salarial " << media << endl;
    for(int i=0; i<n; i++){
        if(f[i].salario > media){
            mostraFuncionario(f[i]);
        }
    }
}

int main(){
    Funcionario f[50];
    int i = 0;
    char opcao;
    do {
        leiaFuncionario(i, f);
        i++;
        opcao = leiaCaracter();
    } while(opcao == 'S');

    relatorio(i, f);
}
