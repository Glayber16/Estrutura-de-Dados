#include <iostream>
#include <string>
#include <new>

using namespace std;

class dicionario{
    struct Noh{
        int chave;
        string nome;
        Noh *prox;
    };

    int n;
    int tam;
    Noh* *v;

    int hatch (int chave){
        return chave % n;
    }

    public:
    string consultar(int chave){
        int i = hatch(chave);
        for(Noh *p = v[i]; p != nullptr; p = p->prox){
            if(chave == p->chave){
                return p->nome;
            }
        }
    }


    dicionario(){
        n = 0;
        tam = 1;
        v = new Noh* [tam];   
        for(int i = 0; i < tam; i++){
            v[i] = nullptr;
        }
    }
    ~dicionario(){
        for(int i = 0; i < tam; i++){
            while(true){
                Noh *noh = v[i];
                if(noh == nullptr){
                    break;
                }
                v[i] = noh->prox;
                delete noh;
            }
        }
        delete[] v;
    }
    void redimensionar(int novo){
        Noh * *U = new Noh* [novo];
        int i;
        for(i = 0; i < novo; i++){
            U[i] = nullptr;
        }
        int antes = tam;
        tam = novo;
        for(i = 0; i < antes; i++){
            Noh *noh = v[i];
            while(noh){
                int j = hatch(noh->chave);
                Noh *inicio = U[j];
                U[j] = noh;
                Noh *proximo = noh->prox;
                noh->prox = inicio;
                noh = proximo;
            }
        } 
        delete v;
        v = U;
    }

    void inserir (int chave, string valor){
        if(consultar(chave) != nullptr){
            return;
        }
        if(n == tam){
            redimensionar(2*tam);
        }
        int i = hatch(chave);
        v[i] = new Noh {chave, valor, v[i]};
        n++;
    }

    void remover(int chave){
        int i = hatch(chave);
        if(v[i] == nullptr){
            return;
        }
        if(v[i]->chave == chave){
            Noh *p = v[i]; 
            v[i] = p->prox;
            delete p;
        }
        else{
            Noh *ant = v[i];
            while(true){
                Noh *p = ant->prox;
                if(p==nullptr){
                    return;
                }
                if(p->chave == chave){
                    ant->prox = p->prox;
                    delete p;
                    return;
                }
                ant = p;
            }
        }
    }

};

int main (){
    dicionario d;
    while(true){
        cout << "I para inserir\n" << "R para remover \n" << "C para consultar \n" << "S para sair \n";
        char c;
        cin >> c;
        if(c == 'I'){
            cout << "Digite a matricula ";
            int x;
            cin >> x;
            cout << "Digite o nome ";
            string y;
            cin >> y;
            d.inserir(x,y);
        }
        if(c == 'R'){
            cout << "Digite a matricula a ser removida ";
            int x;
            cin >> x;
            d.remover(x);
        }
        if(c == 'S'){
            cout << "Programa finalizado\n";
            break;
        }
    }
}