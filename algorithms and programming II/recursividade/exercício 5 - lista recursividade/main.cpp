#include <iostream>

using namespace std;

int MDCRec(int m, int n){
    if(n > m)
        return MDCRec(n, m);
    if(n == 0)
        return m;
    return MDCRec(n, m%n);
}

int main()
{
    int n = 50;
    int m = 35;

    cout << MDCRec(m, n);
}
