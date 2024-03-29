#include <iostream>
#define TMAX 10
using namespace std;


int calculaProdEscalar(int n, int x[], int y[]){
    if(n == 1){
        return x[0] * y[0];
    }
    return x[n-1] * y[n-1] + calculaProdEscalar(n-1, x, y);
}

int main()
{
    int x[TMAX] = {1, 5, 6, 7, 8};
    int y[TMAX] = {3, 4, 7, 8, 9};
    int n = 5;

    cout << calculaProdEscalar(n, x, y);
}
