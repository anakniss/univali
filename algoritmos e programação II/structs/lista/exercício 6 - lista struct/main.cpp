#include <iostream>

using namespace std;

typedef struct {
    string nomeDependente;
    string dataNascimento;
} Dependente;

typedef struct {
    string matricula;
    string nomeSocio;
    Dependente dependentes[5];
    int qtdDependentes;
} Socio;

void leiaDependente(Dependente &d){
    cout << "Informe o nome do dependente: " << endl;
    getline(cin, d.nomeDependente);

    cout << "Informe a data de nascimento do dependente: " << endl;
    getline(cin, d.dataNascimento);
}

int verificaQtdDependentes(){
    int n;

    cout << "Informe a quantidade de dependentes (máximo 5): " << endl;
    cin >> n;

    while(n < 0 or n > 5){

        cout << "Dado invalido. Informe a quantidade de dependentes novamente(máximo 5): " << endl;
        cin >> n;
    }

    return n;
}

void leiaSocio(Socio &s){

    cout << "Informe a matricula do socio: " << endl;
    cin.ignore();
    getline(cin, s.matricula);

    cout << "Informe a nome do socio: " << endl;
    getline(cin, s.nomeSocio);

    s.qtdDependentes = verificaQtdDependentes();

    cin.ignore();

    for(int i=0; i<s.qtdDependentes; i++){
        leiaDependente(s.dependentes[i]);
    }
}

void mostraSocio(Socio &s){
    if(s.qtdDependentes > 0){
        cout << "Nome do socio: " << s.nomeSocio << endl;
        for(int i=0; i<s.qtdDependentes; i++){
            cout << "Nome dependente " << i+1 << ": " << s.dependentes[i].nomeDependente << endl;
        }
    }
    else {
        cout << "O socio possui menos de 3 dependentes";
    }
}

int main()
{
    Socio s;

    leiaSocio(s);
    mostraSocio(s);

}
