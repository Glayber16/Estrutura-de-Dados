#include <iostream>
#include <algorithm>

class ArvoreBinaria {
    struct Noh {
        int chave;
        Noh* esq;
        Noh* dir;
    };
    Noh* raiz;

public:
    ArvoreBinaria() {
        raiz = nullptr;
    }

    void inserir(int chave) {
        raiz = inserirRecursivo(raiz, chave);
    }

    Noh* inserirRecursivo(Noh* noh, int chave) {
        if (noh == nullptr) {
            noh = new Noh{chave, nullptr, nullptr};
        } else if (chave < noh->chave) {
            noh->esq = inserirRecursivo(noh->esq, chave);
        } else if (chave > noh->chave) {
            noh->dir = inserirRecursivo(noh->dir, chave);
        }
        return noh;
    }

    int profundidade(Noh* noh) {
        if (noh == nullptr) {
            return 0;
        } else {
            int esqProf = profundidade(noh->esq);
            int dirProf = profundidade(noh->dir);
            return std::max(esqProf, dirProf) + 1;
        }
    }

    int calcularProfundidade() {
        return profundidade(raiz);
    }
};

int main() {
    ArvoreBinaria arvore;
    arvore.inserir(10);
    arvore.inserir(5);
    arvore.inserir(15);
    arvore.inserir(3);
    arvore.inserir(7);
    arvore.inserir(12);
    arvore.inserir(20);
    arvore.inserir(35);
    arvore.inserir(4);
    arvore.inserir(11);
    std::cout << "A profundidade da árvore é: " << arvore.calcularProfundidade() << std::endl;

    return 0;
}
