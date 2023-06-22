#include <iostream> // EXERC4
#include <fstream>
    using namespace std;
    int main(){
        ifstream arq;
        ofstream arq2;
        char ch;
        string nomearq, nomearq2;
        cout << "Nome do arquivo a ser aberto: ";
        getline(cin, nomearq);
        arq.open(nomearq.c_str()); // cria e abre para leitura

        nomearq2 = nomearq;
        for(int i=nomearq2.size()-1; i>0; i--)
            if(nomearq2.at(i)!='.')
                nomearq2.at(i)='x';
            else break;

        cout << nomearq2 << endl;
        arq2.open(nomearq2.c_str());   // cria e abre pra leitura
        if (!arq or !arq2){
            cout << "Nao foi possivel abrir o arquivo."; cin.get();
            return 0;
        }
        while(arq.get(ch)) {         // enquanto le caracter
            if(ch!='/') arq2<<ch;   // grava caracter normal no arq2
            else  {                  // leitura anterior indicou possivel comentario
                arq.get(ch);        // le 2o caracter
                if(ch!='/' && ch!='*') {     // indica q nao era comentario
                    arq2<<'/'<<ch;  // grava os 2 caracteres lidos
                }
                else                // confirmado comentario
                    if(ch=='/'){     // de linha
                        while(arq.get()!='\n'); //le-descarta resto lin
                        arq2<<'\n';             //grava o final p/pular linha arq2
                    }
                    else{                        // de bloco, sai procurando
                        do{
                            arq.get(ch);        // le caracter
                            if(ch=='*'){
                                arq.get(ch);    // le 2o caracter
                                if(ch=='/') break;
                            }
                        }while(true);
                    }
            }
        }
        return 0;
    }
