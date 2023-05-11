#include <iostream>

using namespace std;

int calculaPolinomio(int b, e, v[]){
    if(e == 0){
        return 0;
    }
    return v[e] * pow(b, e) + calculaPolinomio(b, e-1, v[e]);
}

int main()
{

}
