#include <iostream>
#include <new>

class Conjunto{
    struct Noh{
        double elem;
        Noh *esq;
        Noh *dir;
    };
    Noh *raiz;

    public:

    Conjunto(){
        raiz = nullptr;
    }
    void inserir(double x){
        if(raiz == nullptr){
            raiz = new Noh {x, nullptr, nullptr};
            return;
        }
        Noh *n = raiz;
        while(true){
            if(x == n->elem){
                return;
            }
            if(x < n->elem){
                if(n->esq == nullptr){
                    n->esq = new Noh {x, nullptr, nullptr};
                    return;
                }
                else{
                    n = n->esq;
                }
            }
            if(x > n->elem){
                if(n->dir == nullptr){
                    n->dir = new Noh {x,nullptr, nullptr};
                    return;
                }
                else{
                    n = n->dir;
                }
            }
        }
    }

    void remover(double x){
        Noh *n = raiz;
        Noh *pai = nullptr;
        if(n == nullptr){
            return;
        }
        while(n!= nullptr){
            if(x == n->elem){
                break;
            }
            pai = n;
            if(x < n->elem) {
                n = n->esq;
            }
            if(x > n->elem){
                n = n->dir;
            }
        }
        Noh* *cima;
        if(pai == nullptr){
            cima = &raiz;
        }
        else if(pai->elem < n->elem){
            cima = &pai->dir;
        }
        else if(pai->elem > n->elem){
            cima = &pai->esq;
        }

        if(n->esq == nullptr or n->dir == nullptr){ // 1 filho
            Noh *filho;
            if(n->esq == nullptr){
                filho = n->dir;
            }
            if(n->dir == nullptr) {
                filho = n->esq
            }
            *cima = filho;
        }
        if(n->esq != nullptr and n->dir != nullptr){
            Noh *pai_pred = n;
            Noh *pred = n->esq;
            while(pred->dir != nullptr){
                pai_pred = pred;
                pred = pred->dir;
            }
            if(pred == pai_pred->esq){
                pai_pred->esq = pred->esq;
            }
            if(pred == pai_pred->dir){
                pai_pred->dir = pred->esq;
            }
            pred->esq = n->esq;
            pred->dir = n->dir;
            *cima = pred;
        }
        delete n;
    }

    void imprimir(Noh *n){
        if(n!= nullptr){
            imprimir(n->esq);
            cout << n->elem << "\n";
            imprimir(n->dir);
        }   
    }
    void cres(){
        imprimir(raiz);
    }
    void busca(double x){
        Noh* n = raiz;
        if(n->elem == x){

        }
    }
};