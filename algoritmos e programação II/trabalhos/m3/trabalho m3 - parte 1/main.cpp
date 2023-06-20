#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

typedef struct Nodo{
    string plvra;
    int qtd;
    struct Nodo *proximo;
} Tipolista;

typedef struct{
    char plvra[31];
    int qtd;
} Palavras;

void insereOrdenado(Tipolista **lista, string palavra){
    Tipolista *aux, *p;

    p = new Tipolista;

    if(p==NULL){
        cout << "Sem memoria";
        cin.get();
        exit(1);
    }

    p->plvra = palavra;
    p->qtd = 1;

    if(*lista==NULL){
        p->proximo=NULL;
        *lista = p;
    }
    else if(p->plvra<(*lista)->plvra){
        p->proximo= *lista;
        *lista = p;
    }
    else{
        aux = *lista;

        while(aux->proximo && p->plvra > aux->proximo->plvra)
            aux = aux -> proximo;

        p->proximo = aux -> proximo;
        aux->proximo = p;
    }
}

bool pesquisa(Tipolista *lista, string palavra){
    Tipolista *p = lista;

    while(p!=NULL){
        if(p->plvra==palavra){
            p->qtd++;
            return true;
        }
        p = p->proximo;
    }

    return false;
}

void exibelista(Tipolista *lista){
    Tipolista *p = lista;

    cout << "\nInformacoes lista encadeada:" << endl;

    while(p != NULL){
        cout << "\nNodo: "<< p << endl;
        cout << "palavra: " << p->plvra << endl;
        cout << "qtd: " << p->qtd << endl;
        p = p->proximo;
    }
}

void destroilista(Tipolista **ptr_lista){
    Tipolista *p;

    cout << "\nDestruindo lista..." << endl;

    while(*ptr_lista != NULL){
        p = *ptr_lista;
        *ptr_lista = (*ptr_lista)->proximo;
        delete p;
    }
}

void salvaInfoArq(Tipolista *lista){
    ofstream arqbin("listaPalavras.bin", ios::binary);

    Tipolista *p=lista;
    Palavras pl;

    cout << "\nSalvando informacoes no arquivo binario..." << endl;

    while(p!=NULL){
        strcpy(pl.plvra,p->plvra.c_str());
        pl.qtd = p->qtd;
        arqbin.write((const char*)(&pl),sizeof(Palavras));
        p = p->proximo;
    }

    arqbin.close();
}

void exibeInfoArq(){
    Palavras p;

    ifstream arqbin("listaPalavras.bin", ios::binary);

    cout << "\nInformacoes do arquivo binario:" << endl;

    while(arqbin.read((char*)(&p), sizeof(Palavras))){
        cout << p.plvra << " " << p.qtd << endl;
    }

    arqbin.close();
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

void informaNomeArq(ifstream &arq)
{
    string nomeArq;

    cout << "Nome do arquivo a ser aberto: ";
    getline(cin,nomeArq);
    arq.open(nomeArq.c_str());
}

int main(){
    Tipolista *lista = NULL;
    ifstream arq;
    string palavra = "";
    char ch;
    bool existe;
    char opcao;

    do {
        informaNomeArq(arq);

        while(!arq)
        {
            opcao = leiaSN("Nao foi possivel abrir o arquivo. Deseja tentar novamente? S/N");

            if(opcao == 'S')
            {
                informaNomeArq(arq);
            }
            else {
                cout << "Fechando o programa...";
                exit(0);
            }
        }

        while(!arq.eof()){
            arq.get(ch);
            if(ch == ' ' or ch == '\n' or ch == '.' or arq.eof()){
                if(palavra.size() >= 5){
                    existe = pesquisa(lista, palavra);

                    if(not existe)
                        insereOrdenado(&lista, palavra);

                }
                palavra = "";
            }
            else
                palavra = palavra + ch;
        }
        arq.close();
        exibelista(lista);
        salvaInfoArq(lista);
        destroilista(&lista);
        exibeInfoArq();

        opcao = leiaSN("\nDeseja repetir o processo? S/N");

        if(opcao == 'N')
            cout << "Fechando o programa...";

    } while(opcao == 'S');

    return 0;
}
