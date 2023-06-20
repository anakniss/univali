#include <iostream>
#include <fstream>
#include <string.h>
#define TMAX 31

using namespace std;

typedef struct Nodo {
    char palavra[31];
    int cont = 1;
    struct Nodo *proximo;
} Lista;

void insereFinal(Lista **, char [], int, int &);
Nodo* criaNodo(char [], int);
void destroiLista(Lista **);
void bubbleSort(Lista **, int);
void mostraListaEncad(Lista *);
char leiaSN(string);

int main()
{
    Lista *head = NULL;
    ifstream arquivoE;
    string nomeArq;
    char palavra[TMAX];
    char ch;
    char opcao;
    int k = 0;

    do
    {
        cout << "Informe o nome do arquivo: " << endl;

        getline(cin, nomeArq);

        arquivoE.open(nomeArq.c_str());

        if(!arquivoE)
        {
            cout << "Nao foi possivel abrir o arquivo";
            exit(0);
        }

        while(!arquivoE.eof())
        {
            int n = 0;

            arquivoE.get(ch);

            while(ch != ' ' and ch != '\n' and !arquivoE.eof())
            {
                palavra[n] = ch;
                n++;
                arquivoE.get(ch);
            }

            palavra[n] = '\0';

            if(n >= 5)
            {
                insereFinal(&head, palavra, n, k);
            }
        }

        bubbleSort(&head, k);
        mostraListaEncad(head);
        opcao = leiaSN("Deseja repetir o processo?");

    } while(opcao == 'S');

    return 0;
}

void mostraListaEncad(Lista *head)
{
    cout << "\nESCREVENDO A LISTA ENCADEADA E ORDENADA" << endl;
    while(head != NULL){
        cout << "Palavra: " << head->palavra << endl;
        cout << "Contagem: " << head->cont << endl;
        cout << "Endereco: " << head->proximo << endl;

        head = head->proximo;
    }
}

void insereFinal(Lista **head, char palavra[], int n, int &k){
    Lista *atual, *pAnt;
    int verifica;

    if(*head == NULL) {
        *head = criaNodo(palavra, n);
        k++;
        return;
    }

    atual = *head;

    while(atual != NULL)
    {
        verifica = strcmp(atual->palavra, palavra);

        if(verifica == 0)
        {
            atual->cont++;
            return;
        }

        pAnt = atual;
        atual = atual->proximo;
    }

    pAnt->proximo = criaNodo(palavra, n);
    k++;
}

Nodo* criaNodo(char palavra[], int n){
    Lista *atual;
    atual = new Lista;

    if(atual == NULL){
        cout << "Sem memória";
        cin.get();
        exit(1);
    }

    for(int i=0; i<n; i++){
        atual->palavra[i] = palavra[i];
    }

    atual->palavra[n] = '\0';

    atual->proximo = NULL;

    return atual;
}

void destroiLista(Lista **ptr_lista)
{
    Lista *atual;
    while(*ptr_lista != NULL){
        atual = *ptr_lista;
        *ptr_lista = (*ptr_lista)->proximo;

        delete atual;
    }
}

void bubbleSort(Lista **head, int k)
{
    Lista *atual, *pAnt, *pAntAnt = NULL;
    int verifica;

    if(*head == NULL)
        return;

    if((*head)->proximo == NULL)
        return;

    pAnt = *head;
    atual = pAnt->proximo;

    for(int i=0; i<k; i++)
    {
        pAnt = *head;
        atual = pAnt->proximo;

        while(atual != NULL)
        {
            verifica = strcmp(pAnt->palavra, atual->palavra);

            if(verifica == 1)
            {
                pAnt->proximo = atual->proximo;

                if(pAntAnt != NULL)
                    pAntAnt->proximo = atual;

                atual->proximo = pAnt;

                if(pAnt == *head)
                    *head = atual;

                pAntAnt = atual;
                atual = pAnt->proximo;
            }

            else
            {
                pAntAnt = pAnt;
                pAnt = atual;
                atual = atual->proximo;
            }
        }
    }
}

char leiaSN(string mensagem){
    string opcao;

    cout << mensagem << endl;
    getline(cin, opcao);

    opcao[0] = toupper(opcao[0]);

    while(opcao.size() != 1 or opcao[0] != 'S' and opcao[0] != 'N'){
        cout << "Opcao invalida. Informe novamente: " << endl;
        getline(cin, opcao);
        opcao[0] = toupper(opcao[0]);
    }

    return opcao[0];
}


