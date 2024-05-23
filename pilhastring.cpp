#include <iostream>

using namespace std;

class Pilha{
    int tam;
    string *v;
    int n;

    public:

    Pilha(){
        tam = 1;
        v = new string [tam];
        n = 0;
    }

    void empilhar(string x){
        if(n == tam) {
            tam = tam * 2;
            string *w = new string [tam];
            for(int i = 0; i<n; i++){
                w[i] = v[i];
            }
            delete[] v;
            v = w;
        }
        v[n] = x;
        n++;
    }

    string desimpilhar(){
        string elemento = v[n-1];
        n--;
        return elemento;
    }

    void mostra(){
        for(int i = 0; i < n; i++){
            cout << " " << v[i] << " ";
        }
        cout << "\n";
    }
};

int main (){
    Pilha a;

    while(true){
        int seletor;
        cout << "1 para empilhar, 2 para desimpilhar, 3 para mostrar, 0 para parar ";
        cin >> seletor;
        if(seletor == 0) {
            break;
        }
        if(seletor == 1){
            string palavra;
            cout << "Digite a palavra para ser empilhada \n";
            cin >> palavra;
            a.empilhar(palavra);
        }

        if(seletor == 2){
            cout << "O elemento desimpilhado foi: " << a.desimpilhar() << "\n";
        }

        if(seletor == 3){
            a.mostra();
        }
    }
}