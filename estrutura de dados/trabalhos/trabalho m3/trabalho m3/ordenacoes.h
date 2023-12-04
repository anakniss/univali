#ifndef ORDENACOES_H_INCLUDED
#define ORDENACOES_H_INCLUDED

#include <vector>

template<typename T>
void insertionSort(vector<T>& lista)
{
    int n = lista.size();
    for (int i = 1; i < n; i++) {
        auto chave = lista[i];
        int j = i - 1;

        while (j >= 0 && chave < lista[j]) {
            lista[j + 1] = lista[j];
            j--;
        }
        lista[j + 1] = chave;
    }
}

#endif // ORDENACOES_H_INCLUDED
