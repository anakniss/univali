#include <iostream>

using namespace std;

typedef struct {
    int numerador;
    int denominador;
} Fracao;

void lerFracao(Fracao &p){
    cout << "Informe o numerador: " << endl;
    cin >> p.numerador;
    cout << "Informe o denominador: " << endl;
    cin >> p.denominador;
}

void mostraFracao(Fracao f1, Fracao f2){
    cout << "Numerador: " << f1.numerador << endl;
    cout << "Denominador: " << f1.denominador << endl;

    cout << "Numerador: " << f2.numerador << endl;
    cout << "Denominador: " << f2.denominador << endl;
}

void soma(Fracao f1, Fracao f2, Fracao &x){
    if(f1.denominador == f2.denominador){
        x.denominador = f1.denominador;
        x.numerador = f1.denominador + f2.denominador;
    }
    else {
        x.denominador = f1.denominador * f2.denominador;
        x.numerador = (x.denominador / f1.denominador * f1.numerador) + (x.denominador / f2.denominador * f2.numerador);
    }
}

Fracao somaFracao(Fracao f1, Fracao f2){
    Fracao x;
    if(f1.denominador == f2.denominador){
        x.denominador = f1.denominador;
        x.numerador = f1.denominador + f2.denominador;
    }
    else {
        x.denominador = f1.denominador * f2.denominador;
        x.numerador = (x.denominador / f1.denominador * f1.numerador) + (x.denominador / f2.denominador * f2.numerador);
    }
}

void sub(Fracao f1, Fracao f2, Fracao &x){
    if(f1.denominador == f2.denominador){
        x.denominador = f1.denominador;
        x.numerador = f1.denominador + f2.denominador;
    }
    else {
        x.denominador = f1.denominador * f2.denominador;
        x.numerador = (x.denominador / f1.denominador * f1.numerador) + (x.denominador / f2.denominador * f2.numerador);
    }
}

void mult(Fracao f1, Fracao f2, Fracao &x){
    x.numerador = f1.numerador * f2.numerador;
    x.denominador = f1.denominador * f2.denominador;
}

void div(Fracao f1, Fracao f2, Fracao &x){
    x.numerador = f1.numerador * f2.denominador;
    x.denominador = f2.numerador * f1.denominador;
}

int main()
{
    Fracao f1, f2, x;

    lerFracao(f1);
    lerFracao(f2);

    soma(f1, f2, x);
    mostraFracao(f1, f2);

    //Fracao soma = somaFracao(f1, f2);
    //cout << "Soma diferente: " << soma << endl;

    sub(f1, f2, x);
    mostraFracao(f1, f2);

    mult(f1, f2, x);
    mostraFracao(f1, f2);

    div(f1, f2, x);
    mostraFracao(f1, f2);
}
