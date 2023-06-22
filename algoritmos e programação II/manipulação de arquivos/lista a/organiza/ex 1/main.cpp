#include <iostream> // EXERC4
#include <fstream>
using namespace std;
int main(){
    string linha;
    int br;
    rename("TEXTO80.txt", "TEXTO80.bak"); // renomear
    ifstream arq("TEXTO80.bak");
    ofstream arq2("TEXTO80.txt");
    // checar se deu pra abrir
    while(getline(arq,linha)){
        br=(80-linha.size())/2;
        for(int i=1; i<=br; i++) arq2<<' ';
        arq2<<linha<<endl;
    }
    arq.close();
    arq2.close();
    remove("TEXTO80.bak"); // para deletar o antigo
    return 0;
}
