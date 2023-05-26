#include <iostream>
#include <cstdlib>
using namespace std;

typedef struct Nodo{
    string nome;
    float peso;
    struct Nodo *proximo;
} Tipolista;

void destroilista(Tipolista **);
void exibelista(Tipolista *);
Tipolista* montaLista();
float pesoMedio(Tipolista *);
void exibeAbaixoPeso(Tipolista *);
Tipolista * retornaEndereco(Tipolista *, string);

int main(){
    Tipolista *p, *umalista = montaLista();
    exibelista(umalista);
    cout << "Peso medio desta turma "<< pesoMedio(umalista) << endl;
    exibeAbaixoPeso(umalista);
    p = retornaEndereco(umalista,"fernanda");
    if(p==NULL) cout<< "nao tem fernanda";
    else cout<< "Fernanda tah em "<< p<<endl;
    destroilista(&umalista);
    return 0;
}
Tipolista* montaLista(){
    Tipolista *p, *paux, *lista=NULL;
    char resp;
    do{
        p = new Tipolista; // checar se da certo
        cout <<"Nome ";
        getline(cin,p->nome);
        cout <<"Peso ";
        cin>> p->peso;
        cin.ignore();
        if(lista==NULL) {lista = p; paux = p;}
        else{
            paux->proximo = p; // conecta o novo
            paux = p; // aponta pro novo
        }
        cout<<"Outro? S/N";
        resp=toupper(cin.get());
        cin.ignore();
    }while(resp !='N');
    p->proximo= NULL;
    return lista;
}
void destroilista(Tipolista **ptr_lista)    // ponteiro de ponteiro
{
    Tipolista *p;
    while (*ptr_lista != NULL){
        p = *ptr_lista;
        *ptr_lista = (*ptr_lista)->proximo;
        delete p;
    }
}
void exibelista(Tipolista *lista){
    Tipolista *p = lista;
    cout << "Conteudo da Lista "<< endl;
    while (p != NULL){
        cout << "Dados " << p->nome<< " "<< p->peso<<endl;
        p = p->proximo;
    }
}
float pesoMedio(Tipolista *p){
    int cont=0; float total=0;
    while (p != NULL){
        total+= p->peso; cont++;
        p = p->proximo;
    }
    return total/cont;
}
void exibeAbaixoPeso(Tipolista *p){
    cout<<"Abaixo dos 50kg" << endl;
    while (p != NULL){
        if(p->peso < 50)
        cout << p->nome<<" "<< p->peso <<endl;
        p = p->proximo;
    }
}
Tipolista * retornaEndereco(Tipolista *p, string elemento){
    if (p==NULL)    // se lista vazia
        return NULL;
    while (p != NULL and p->nome != elemento){
        p=p->proximo;
    }
    return p; // q serah nulo pq nao achou ou o endereco
}

Lista* procuraElemento(Lista* head, string elemento){
    Lista* atual = head;
    while(atual != NULL){
        if(atual->dado == elemento){
            return atual;
        }
        atual = atual->proximo;
    }
    return NULL;
}
