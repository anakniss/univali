#include <iostream>
#include <math.h>
using namespace std;
struct Ponto
{
 int X, Y;
};
Ponto cria (int X, int Y)
{
     Ponto p;
     p.X = X;
     p.Y = Y;
     return p;
}
int recuperaX (Ponto p){
    return p.X;
}
int recuperaY (Ponto p){
    return p.Y;
}
void setaX (Ponto &p, int X){
    p.X = X;
}
void setaY (Ponto &p, int Y){
    p.Y = Y;
}
void mostra(Ponto p){
    cout << "X = " << p.X << " Y = " << p.Y << endl;
}
float distancia (Ponto p1, Ponto p2){
     int dx = p1.X - p2.X;
     int dy = p1.Y - p2.Y;
     return sqrt(pow(dx, 2) + pow(dy, 2));
}
int main()
{
     Ponto p1, p2;
     p1 = cria(2, 9);
     p2 = cria(3, 5);
     mostra(p1);
     mostra(p2);
     setaX(p1, 4);
     mostra(p1);
     cout << distancia (p1, p2);
     return 0;
}
