#include <iostream>

using namespace std;

void escreveSequenciaRecursiva(int n){
    if(n == 1){
        cout << n;
    }

    else {
        escreveSequenciaRecursiva(n - 1);

        if(n % 2 == 0){
            cout << ", " << n*n;
        }
        else{
            cout << ", " << n;
        }
    }

}

int main()
{
    escreveSequenciaRecursiva(10);
}
