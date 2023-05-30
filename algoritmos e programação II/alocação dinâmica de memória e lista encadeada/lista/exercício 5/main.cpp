#include <iostream>

using namespace std;

//Suponha a existência de uma lista encadeada com as matrículas de um conjunto de funcionários.
//Admita também que exista outra lista encadeada onde cada nodo contenha matrícula do funcionário e
//nome do seu dependente. Faça um procedimento que escreva, para cada funcionário, o nome do
//seu(s) dependente(s).

typedef struct Nodo {
    string matricula;
    struct Nodo *proximo;
} Lista;

typedef struct Nodo2 {
    string matricula;
    string nomeDep;
    struct Nodo2 *proximo;
} Lista2;

void insereFinal(Lista **);
void destroiLista(Lista **);
void exibeLista(Lista *);

void insereFinal2(Lista2 **);
void destroiLista2(Lista **);
void exibeLista2(Lista2 *);

int leiaMenu();
void mostraDependentes(Lista *, Lista2 *);

int main()
{
    Lista *head = NULL;
    Lista2 *head2 = NULL;

    int opcao;

    while(true){
        opcao = leiaMenu();

        switch(opcao){
            case 1:
                cout << "Opcao 1 selecionada" << endl;
                insereFinal(&head);
                break;
            case 2:
                cout << "Opcao 2 selecionada" << endl;
                insereFinal2(&head2);
                break;
            case 3:
                cout << "Opcao 3 selecionada" << endl;
                if(head != NULL){
                    exibeLista(head);
                    break;
                }
                else {
                    cout << "Nao existem valores a serem mostrados" << endl;
                    break;
                }
            case 4:
                cout << "Opcao 4 selecionada" << endl;
                if(head2 != NULL){
                    exibeLista2(head2);
                    break;
                }
                else {
                    cout << "Nao existem valores a serem mostrados" << endl;
                    break;
                }
            case 5:
                cout << "Opcao 5 selecionada" << endl;
                mostraDependentes(head, head2);
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

int leiaMenu(){
    int opcao;
    cout << "======================= MENU =======================" << endl;
    cout << "1 - Adicionar nova matricula na lista 1" << endl;
    cout << "2 - Adicionar novos elementos na lista 2" << endl;
    cout << "3 - Exibir lista 1" << endl;
    cout << "4 - Exibir lista 2" << endl;
    cout << "5 - Pesquisar funcionarios com dependentes" << endl;
    cout << "6 - Sair" << endl;
    cout << "====================================================" << endl;
    cout << "Informe a opcao desejada: " << endl;
    cin >> opcao;

    return opcao;
}

void insereFinal(Lista **head){
    Lista *atual, *pant;
    atual = new Lista;

    if(atual == NULL){
        cout << "Sem memória";
        cin.get();
        exit(1);
    }
    cout << "Informe a matricula do funcionario: " << endl;
    cin >> atual->matricula;

    atual->proximo = NULL;

    if(*head == NULL) {
        *head = atual;
        return;
    }

    pant = *head;
    while(pant->proximo != NULL) {
        pant = pant->proximo;
    }

    pant->proximo = atual;
}

void destroiLista(Lista **ptr_lista) {
    Lista *p;
    while(*ptr_lista != NULL){
        p = *ptr_lista;
        *ptr_lista = (*ptr_lista)->proximo;
        delete p;
    }
}

void exibeLista(Lista *head){
    while(head != NULL){
        cout << "Matricula: " << head->matricula << endl;
        head = head->proximo;
    }
}

Lista* retornaEndereco(Lista *head, string elemento){
    if(head == NULL)
        return NULL;
    while(head != NULL and head->matricula != elemento){
        head = head->proximo;
    }
    return head;
}

void insereFinal2(Lista2 **head){
    Lista2 *atual, *pant;
    atual = new Lista2;

    if(atual == NULL){
        cout << "Sem memória";
        cin.get();
        exit(1);
    }

    cout << "Informe a matricula do funcionario: " << endl;
    cin >> atual->matricula;

    cin.ignore();

    cout << "Informe o nome do dependente: " << endl;
    getline(cin, atual->nomeDep);

    atual->proximo = NULL;

    if(*head == NULL) {
        *head = atual;

        return;
    }

    pant = *head;
    while(pant->proximo != NULL) {
        pant = pant->proximo;
    }

    pant->proximo = atual;

}

void destroiLista2(Lista2 **head) {
    Lista2 *atual;
    while(*head != NULL){
        atual = *head;
        *head = (*head)->proximo;
        delete atual;
    }
}

void exibeLista2(Lista2 *head){
    while(head != NULL){
        cout << "Matricula: " << head->matricula << endl;
        cout << "Nome do dependente: " << head->nomeDep << endl;
        cout << "====================================================" << endl;
        head = head->proximo;
    }
}

Lista2* retornaEndereco2(Lista2 *head, string elemento){
    if(head == NULL)
        return NULL;
    while(head != NULL and head->matricula != elemento){
        head = head->proximo;
    }
    return head;
}

void mostraDependentes(Lista *head, Lista2 *head2){
    bool flag;
    Lista2 *atual = head2;

    while(head != NULL){
        flag = false;
        while(atual != NULL){
            if(atual->matricula == head->matricula){
                if(flag == false){
                  cout << "Matricula funcionario: " << atual->matricula << endl;
                  flag = true;
                }
                cout << "Nome do dependente: " << atual->nomeDep << endl;
            }
            atual = atual->proximo;
        }
        if(flag == false){
            cout << "Funcionario " << head->matricula << " nao possui dependentes" << endl;
        }
        head = head->proximo;
        atual = head2;
    }
}
