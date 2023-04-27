#include <iostream>
#define TMAX 30

using namespace std;

int main()
{
    int i, j, n;
    string nomes[TMAX];
    string notas[TMAX];
    string nome;
    char opcao;

    bool iguais = true;

    cout << "Informe o tamanho da turma (máximo 30): " << endl;
    cin >> n;

    while(n < 0 or n > 30){
        cout << "O valor não está dentro do requisito. Informe um novo valor: " << endl;
        cin >> n;
    }

    for(i=0; i<n; i++){
        cout << "Informe o nome do estudante: " << endl;
        cin.ignore();
        getline(cin, nomes[i]);

        cout << "Informe a nota final do estudante: " << endl;
        cin >> notas[i];
    }

    do {
        cout << "Informe o nome do aluno a ser pesquisado: " << endl;
        cin.ignore();
        getline(cin, nome);

            for(i=0; i<n; i++){
                if(nomes[i].size() != nome.size()){
                    iguais = false;
                }
                else
                    if (nomes[i].size() == nome.size()) {
                        for(j=0; j<nomes[i].size(); j++){
                            if(nomes[i][j] == nome[j]){
                                iguais = true;
                            }
                        }
                        if(iguais == true){
                            cout << "Nome: " << nomes[i] << endl;
                            cout << "Notas: " << notas[i] << endl;
                        }
                    }
                }

        cout << "Gostaria de verificar um novo aluno?" << endl;
        cin >> opcao;
    } while(opcao == 'S');
}
