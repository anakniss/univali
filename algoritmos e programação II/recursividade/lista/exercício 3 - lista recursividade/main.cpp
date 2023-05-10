#include <iostream>

using namespace std;

int calculaMultiplosdeCinco(int num){
    if(num == 0){
        return 0;
    }
    return num + calculaMultiplosdeCinco(num - 5);
}

int main()
{
    cout << calculaMultiplosdeCinco(1000) << endl;

}
