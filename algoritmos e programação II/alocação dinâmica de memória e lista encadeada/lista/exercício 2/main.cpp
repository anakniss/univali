#include <iostream>
#include <cstdlib>

using namespace std;

//Considerando nome e peso de um número qualquer de pessoas, elabore funções e procedimentos para
//i) armazenar em uma estrutura de lista encadeada essas informações;
//ii) calcular e escrever o peso médio;
//iii) escrever o nome das pessoas com peso inferior a 50kg;
//iv) verificar se uma determinada pessoa está representada na lista.

typedef struct Nodo{
    string nome;
    float peso;
    struct Nodo *proximo;
}Lista;

int leiaMenu();
Lista* montaLista();
void destroiLista(Lista **);
void exibaLista(Lista *);
void pesoAbaixo(Lista*, float);
void pesoMedio(Lista *);
float limitaPesoAbaixo();
void procuraElemento(Lista *);

using namespace std;

int main()
{
    Lista *head = montaLista();
    float limite = limitaPesoAbaixo();

    int opcao;

    while(true){
        opcao = leiaMenu();

        switch(opcao){
            case 1:
                cout << "Opcao 1 selecionada" << endl;
                if(head != NULL){
                    exibaLista(head);
                    break;
                }
                else {
                    cout << "Nao existe lista a ser destruida" << endl;
                }

            case 2:
                cout << "Opcao 2 selecionada" << endl;
                if(head != NULL){
                    destroiLista(&head);
                    break;
                }
                else {
                    cout << "Nao existe lista a ser destruida" << endl;
                    break;
                }
            case 3:
                cout << "Opcao 3 selecionada" << endl;
                if(head != NULL){
                    pesoMedio(head);
                    break;
                }
                else {
                    cout << "Nao existe lista a ser calculada" << endl;
                    break;
                }

            case 4:
                cout << "Opcao 4 selecionada" << endl;
                if(head != NULL){
                   pesoAbaixo(head, limite);
                    break;
                }
                else {
                    cout << "Nao existe lista a ser calculada" << endl;
                    break;
                }
            case 5:
                cout << "Opcao 5 selecionada" << endl;
                procuraElemento(head);
                break;

            case 6:
                cout << "Saindo do programa";
                return 0; // sai da função main
            default:
                cout << "Opcao invalida" << endl;
                break;
        }
    }
}

float limitaPesoAbaixo(){
    float peso;

    cout << "Informe o peso a ser considerado abaixo: " << endl;
    cin >> peso;

    return peso;
}

int leiaMenu(){
    int opcao;
    cout << "======================= MENU =======================" << endl;
    cout << "1 - Exibir os valores de cada elemento da lista" << endl;
    cout << "2 - Destruir a lista" << endl;
    cout << "3 - Verificar peso medio" << endl;
    cout << "4 - Verificar abaixo do limite" << endl;
    cout << "5 - Pesquisar pessoa na lista" << endl;
    cout << "6 - Sair" << endl;
    cout << "====================================================" << endl;
    cout << "Informe a opcao desejada: " << endl;
    cin >> opcao;

    return opcao;
}

Lista* montaLista(){
    Lista* atual, *paux, *lista = NULL;
    char opcao;

    do {
        atual = new Lista;

        cout << "Informe o nome: " << endl;
        getline(cin, atual->nome);

        cout << "Informe o peso:" << endl;
        cin >> atual->peso ;

        cin.ignore();

        if(lista == NULL){
            lista = atual;
            paux = atual;
        }
        else {
            paux->proximo = atual;
            paux = atual;
        }
        cout << "Deseja adicionar outro elemento na lista? S/N" << endl;
        opcao = toupper(cin.get());

        cin.ignore();

    } while(opcao != 'N');

    atual->proximo = NULL;

    return lista;
}

void destroiLista(Lista **ptr_lista){
    Lista *atual;
    while(*ptr_lista != NULL){
        atual = *ptr_lista;
        *ptr_lista = (*ptr_lista)->proximo;

        delete atual;
    }
}

void exibaLista(Lista *lista){
    Lista *atual = lista;
    while(atual != NULL){
        cout << "Nome: " << atual->nome << endl;
        cout << "Peso: " << atual->peso << endl;
        cout << "====================================================" << endl;

        atual = atual->proximo;
    }
}

void pesoAbaixo(Lista* head, float limite){
    if(head != NULL){
       cout << "Abaixo dos " << limite << " kg" << endl;

        do {
            if(head->peso < limite){
                cout << "Nome: " << head->nome << endl;
                cout << "Peso: " << head->peso << endl;
                cout << "====================================================" << endl;
            }
            head = head->proximo;
        } while(head != NULL);
    }
}

void pesoMedio(Lista *head){
    float soma = 0;
    int cont = 0;

    while(head != NULL){
        soma += head->peso;
        cont++;

        head = head->proximo;
    }
    cout << "Media: " << soma / float(cont) << endl;
    cout << "====================================================" << endl;
}

void procuraElemento(Lista *head){
    string nome;

    cin.ignore();

    cout << "Informe o nome que deseja procurar: " << endl;
    getline(cin, nome);

    while(head != NULL){
        if (head->nome == nome){
            cout << nome << "está representado(a) no endereço " << head << " da lista" << endl;
            return;
        }

        head = head->proximo;
    }

    cout << "Nome não encontrado" << endl;
    return;
}



