#include <iostream>
#include <string>

using namespace std;

class pilha {

    int tam;
    string* v;
    int n;

public:

    pilha() {
        tam = 1;
        v = new string[tam];
        n = 0;
    }

    void empilhar(string s) {
        if (n == tam) {
            tam = tam * 2;
            string* w = new string[tam];
            for (int i = 0; i < n; i++) {
                w[i] = v[i];
            }
            delete[] v;
            v = w;
        }
        v[n] = s;
        n++;
    }

    string topo() {
        return v[n - 1];
    }

    string desempilhar() {
        if (n == tam / 4) {
            tam = tam / 2;
            string* w = new string[tam];
            for (int i = 0; i < n; i++) {
                w[i] = v[i];
            }
            delete[] v;
            v = w;
        }
        string elemento = topo();
        n--;
        return elemento;
    }

    void desempilhar_sem_retorno() {
        n--;
    }

    int tamanho() {
        return n;
    }

    ~pilha() {
        delete[] v;
    }

    void mostrar(){
        cout << "Pilha: ";
        for(int i = 0; i < n; i++){
            cout << v[i] << " ";
        }
        cout << "\n";
    }

};

class filaDuasPilhas {
private:
    pilha pilha1;  // Pilha para inserção
    pilha pilha2; // Pilha para remoção

public:
    void enqueue(string elemento) {
        pilha1.empilhar(elemento);
    }

    string dequeue() {
        if (pilha2.tamanho() == 0) {
            // Transferir elementos de inbox para outbox se outbox estiver vazio
            while (pilha1.tamanho() > 0) {
                pilha2.empilhar(pilha1.desempilhar());
            }
        }

        if (pilha2.tamanho() == 0) {
            cout << "A fila está vazia!" << "\n";
            return ""; // Valor sentinela para indicar fila vazia
        }

        return pilha2.desempilhar();
    }

    bool isEmpty() {
        return pilha1.tamanho() == 0 && pilha2.tamanho() == 0;
    }

    void mostra(){
        pilha1.mostrar();
        pilha2.mostrar();
}
};

int main() {
    filaDuasPilhas fila;

    while(true){
        int op;
        cout << "Digite 1 para enfilar, 2 para desenfilar, 3 para mostrar a fila, 0 para parar ";
        cin >> op;
        if(op == 1){
            string x;
            cout << "Digite o valor para enfilar\n";
            cin >> x;
            fila.enqueue(x);
        }
        if(op == 2){
            fila.dequeue();
        }
        if(op == 3){
            fila.mostra();
        }
        if(op == 0){
            cout << "Programa encerrado ";
            break;
        }
    }

    return 0;
}
