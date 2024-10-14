#include <iostream>

using namespace std;

long somaMultiplos5(int n){
    if(n == 0){
        return 0;
    }
    return n + somaMultiplos(n-5);
}

int main()
{
    somaMultiplos(1000);
}
