#include <iostream>
#include <new>
#include <string>
using namespace std;

class dici{
    struct Noh{
        int chave;
        string nome;
        Noh *prox;
    };
    int tam;
    int n;
    Noh* *v;
    
    int h(int chave){
        return chave % tam;
    }

    public:

    void inserir(int chave, string nome){
        int i = h(chave);
        v[i] = new Noh{chave, nome, v[i]};
        n++;
    }

    void remover(int chave){
        
    }
};