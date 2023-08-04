#include <iostream>
#include <numbers>
#define pi 3,14

using namespace std;

typedef struct Circ{
    int X, Y, R;
};

Circ cria(){
    cout << "Informe o valor de X" << endl;
    cin >> c.X;

    cout << "Informe o valor de Y" << endl;
    cin >> c.Y;

    cout << "Informe o valor do raio" << endl;
    cin >> c.R;

    return c;
}

int recuperaRaio(Circ c){
    return c.R;
}

int recuperaX(Circ c){
    return c.X;
}

int recuperaY(Circ c){
    return c.X;
}

int calculaDiametro(Circ c){
    return c.R * 2;
}

int calculaPerimetro(Circ c){
    return 2 * pi * c.R;
}

void alteraRaio(Circ &c){
    cout << "Informe o novo valor do raio: " << endl;
    cin >> c.R;
}

void alteraRaio(Circ &c){
    cout << "Informe o novo valor do ponto X: " << endl;
    cin >> c.X;
}

void alteraRaio(Circ &c){
    cout << "Informe o novo valor do ponto Y: " << endl;
    cin >> c.Y;
}

void comparaCirc(Circ p1, Circ p2){
    if(p1.R == p2.R){
        cout << "As circunferencias sao iguais" << endl;
    }
    else if(p1.R > p2.R){
        cout << "A circunferencia P1 eh maior que P2";
    }
    else {
        cout << "A circunferencia P2 eh maior que P1";
    }
}

void comparaPosicao(){


}

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
