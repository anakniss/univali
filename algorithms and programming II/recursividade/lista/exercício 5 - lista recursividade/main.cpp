#include <iostream>

using namespace std;

int calculaMDC(int m, int n){
    if(n > m){
        return calculaMDC(n, m);
    }
    else if(n == 0){
        return m;
    }
    else {
        return calculaMDC(n, m%n);
    }
}

int main()
{
    cout << calculaMDC(10, 2);
}
