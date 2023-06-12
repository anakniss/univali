#include <iostream>
#include <vector>

using namespace std;

/*P9.8. Escreva uma função predicado bool same_set(vector<int> a, vector<int>
b) que verifica se dois vetores têm os mesmos elementos em alguma ordem, ignorando
multiplicidades.
P.ex., os dois vetores 1,4,9,16,9,7,4,9,11 e 11,11,7,9,16,4,1 seriam considerados idênticos.
Você provavelmente vai precisar de uma ou mais funções auxiliares*/

void read_numbers(string, vector<int> &);
bool same_set(vector<int>, vector<int>);
bool check_existence(vector<int>, vector<int>);
bool find_element(int, vector<int>);

int main()
{
    vector<int> a;
    vector<int> b;

    read_numbers("Informe um valor a ser adicionado no vetor A: ", a);
    read_numbers("Informe um valor a ser adicionado no vetor B: ", b);

    bool result = same_set(a, b);

    if(result == false)
        cout << "Vetores NAO identicos";
    else
        cout << "Vetores identicos";
}

void read_numbers(string message, vector<int> &vector){
    char option;
    int n;
    do {
        cout << message << endl;
        cin >> n;

        vector.push_back(n);

        cin.ignore();

        cout << "Outro? S/N" << endl;
        option = toupper(cin.get());

    } while(option != 'N');
}

bool same_set(vector<int> a, vector<int> b)
{
    bool is_valid_a = check_existence(a, b);
    bool is_valid_b = check_existence(b, a);

    return is_valid_a and is_valid_b;
}

bool check_existence(vector<int> first, vector<int> second)
{
    for(int i=0; i<first.size(); i++)
    {
        bool found = find_element(first[i], second);

        if(found == false)
            return false;
    }

    return true;
}

bool find_element(int n, vector<int> second)
{
    for(int j=0; j<second.size(); j++)
        if(n == second[j])
            return true;

    return false;
}




