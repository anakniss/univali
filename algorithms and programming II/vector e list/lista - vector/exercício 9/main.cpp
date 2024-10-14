#include <iostream>
#include <vector>

using namespace std;

/*P9.9. Escreva uma função predicado bool same_elements(vector<int> a,
vector<int> b) que verifica se dois vetores têm os mesmos elementos em alguma
ordem,com as mesmas multiplicidades.
P.ex., 1,4,9,16,9,7,4,9,11 e 11,1,4,9,16,9,7,4,9 seriam considerados idênticos, mas
1,4,9,16,9,7,4,9,11,3,5,2 e 11,11,7,9,16,4,1 não seriam. Você provavelmente vai precisar de
uma ou mais funções auxiliares.
*/

bool same_elements(vector<int>, vector<int>);
void read_numbers(string, vector<int> &);

int main()
{
    vector<int> a;
    vector<int> b;

    read_numbers("Informe um valor a ser adicionado no vetor A: ", a);
    read_numbers("Informe um valor a ser adicionado no vetor B: ", b);

    bool result = same_elements(a, b);

    if(result == true)
        cout << "Vetores identicos" << endl;
    else
        cout << "Vetores NAO identicos" << endl;

    return 0;
}

void read_numbers(string message, vector<int> &vector)
{
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

bool same_elements(vector<int> a, vector<int> b)
{
    vector<bool> check;
    bool flag;

    if(a.size() != b.size())
        return false;

    for(int i=0; i<b.size(); i++)
    {
        check.push_back(false);
    }

    for(int i=0; i<a.size(); i++)
    {
        flag = false;

        for(int j=0; j<b.size(); j++)
        {
            if(a[i] == b[j])
            {
                if(check[j] == false)
                {
                    check[j] = true;
                    flag = true;
                    break;
                }
            }
        }

        if(flag == false)
        {
            return false;
        }
    }

    for(int i=0; i<b.size(); i++){
        if(check[i] == false)
            return false;
    }

    return true;
}
