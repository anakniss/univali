#include <iostream>

using namespace std;

void escreveSerieRec(int n){
    if(n == 1)
        cout << n;
    else {
        escreveSerieRec(n -1);
        if(n % 2 == 0)
            cout << "," << n*n;
        else
            cout << "," << n;
    }
}

int main()


{
    int n = 100;
    escreveSerieRec(n);
}
