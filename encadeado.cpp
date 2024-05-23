#include <iostream>
#include <new>
#include <string>

using namespace std;

class Pilha{

    struct Noh{
        string elemento;
        Noh* prox;
    };
    Noh *topo;

    public:

    string busca(string elemento){
        string tarr = "tarr";
        string enne = "enne";
        while(topo!= nullptr){
            Noh *atual = topo;
            if(elemento == atual->elemento){
                return tarr;
            }
            topo = topo->prox;
        }
        return enne;
    }

    string consulta(){
        return topo->elemento;
    }
    
    Pilha(){
        topo = nullptr;
    }

    ~Pilha() {
        while(topo != nullptr){
            Noh *atual = topo;
            topo = topo->prox;
            delete atual;
        }
    }

    void empilhar(string elemento){
        Noh *p = new Noh;
        p->prox = topo;
        p->elemento = elemento;
        topo = p;
    }

    string desimpilhar(){
        Noh *p = topo;
        string elem = p->elemento;
        topo = topo->prox;
        delete p;
        return elem;
    }

    void printar(){
        Noh *atual = topo;
        for(; topo!= nullptr; topo = topo->prox){
            cout<< atual->elemento << "\n";
            
        }
    }
};

int main (){
    Pilha a;
    while(true){
        int op;
        cout << "1 para enfilar, 2 para desinfilar, 3 para printar, 0 para parar \n";
        cin >> op;
        if(op == 1){
            string x;
            cout << "Digite o valor pra ser enfilado\n";
            cin >> x;
            a.empilhar(x);
        }
        if(op == 2){
            a.desimpilhar();
        }
        if(op == 3){
            a.printar();
        }
        if(op==4){
            string x;
            cout<<"Digite o q quer buscar ";
            cin>> x;
            cout << a.busca(x);
        }
        if(op == 0){
            cout << "Fim do programa\n";
            break;
        }
    }
    
}