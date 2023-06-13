#include <iostream>
#include <vector>

using namespace std;

/*P9.10. Escreva uma função que remove duplicatas de um vetor.
P. ex., se remove_duplicates é chamada com um vetor contendo 1,4,9,16,9,7,4,9,11
então o vetor é mudado para 1,4,9,16,7,11*/

void read_numbers(string, vector<int> &);
void remove_duplicates(vector<int> &);

int main()
{
    vector<int> a;

    read_numbers("Informe um valor a ser adicionado no vetor A: ", a);

    cout << "VETOR ANTES DA EXCLUSAO DE DUPLICATAS" << endl;
    for(int i=0; i<a.size(); i++)
    {
        cout << a[i] << endl;
    }

    remove_duplicates(a);

    cout << "VETOR APOS EXCLUSAO DE DUPLICATAS" << endl;

    for(int i=0; i<a.size(); i++)
    {
        cout << a[i] << endl;
    }

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

void remove_duplicates(vector<int> &a)
{
    for(int i=0; i < a.size(); i++)
    {
        for(int j=i+1; j < a.size(); j++)
        {
            if(a[i] == a[j])
            {
                a.erase(a.begin() + j);
                j--;
            }
        }
    }
}
