#include <iostream>
#define pi 3,14
#define TMAX 5
using namespace std;

typedef struct Circ{
    int X, Y, R;
};

Circ cria(){

    Circ c;

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

void alteraX(Circ &c){
    cout << "Informe o novo valor do ponto X: " << endl;
    cin >> c.X;
}

void alteraY(Circ &c){
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

void comparaPosicao(Circ p1, Circ p2){
    if(p1.R == p2.R && p1.X == p2.X && p2.Y == p2.Y){
        cout << "Ambas circunferencias possuem a mesma posição";
    }
}

void criaCircs(Circ circs[], int tam){
    cout << "Criando circunferencias..." << endl;

    for(int i = 0; i < tam; i++){
        if(i == 3){
            circs[i].X = circs[0].X;
            circs[i].Y = circs[0].Y;
            circs[i].R = circs[0].R * 5;

            cout << "Circunferencia de numero " << i + 1 << " criada" << endl;
        }
        else if(i == 4){
            circs[i].X = circs[2].Y / 10;

            cout << "Informe o valor de Y" << endl;
            cin >> circs[i].Y;

            cout << "Informe o valor do raio" << endl;
            cin >> circs[i].R;

            cout << "Circunferencia de numero " << i + 1 << " criada" << endl;
        }
        else {
            circs[i] = cria();

            cout << "Circunferencia de numero " << i + 1 << " criada" << endl;
        }
    }
}

int main()
{
    Circ circs[TMAX];

    criaCircs(circs, TMAX);

    for(int i=0; i < TMAX; i++){
        cout << "Repassando... Circunferencia de numero " << i << endl;
        cout << "X" << circs[i].X << endl;
        cout << "Y" << circs[i].Y << endl;
        cout << "R" << circs[i].R << endl;
    }

    return 0;
}
