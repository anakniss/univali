#include <iostream>
#include "filaCircularGenerica.h"

/*Desenvolva um programa para simular uma bilheteria de um cinema durante os 45 minutos que
antecedem a sessão. A cada minuto chegam de 2 a 4 pessoas, que são dispostas em uma fila. Antes
do início da abertura da bilheteria já se encontram 12 pessoas na fila. Existe apenas um atendente,
que demora 30 segundos para vender um bilhete.

Indique o número de pessoas que vieram assistir determinado filme e quantas pessoas estavam na
fila da bilheteria quando a sessão teve início. */

int main()
{
    FilaCircular<int, 80> fila;

    cria(fila);

    for (int i = 0; i < 12; i++) {
        insere(fila, rand() % 40);
    }

    int totalPessoas = fila.cardinalidade;

    for (int i = 0; i < 45; i++) {

        int pessoasACadaMinuto = rand() % 2 + 2;
        for (int j = 0; j < pessoasACadaMinuto; j++) {
            insere(fila, rand() % 40);
            totalPessoas++;
        }

        for (int j = 0; j < 2; j++) {
            remove(fila);
        }
    }

    cout << "Numero de pessoas que vieram assistir o filme: " << totalPessoas << endl;
    cout << "Numero de pessoas que estavam na fila quando a sessao teve inicio: " << fila.cardinalidade;
}
