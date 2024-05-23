#include <iostream>
#include <new>

using namespace std;

class pilha{

    int tam;
    double *v;
    int n;

    public:

    pilha(){
        tam = 1;
        v = new double [tam];
        n = 0;
    }

    ~pilha(){
        delete[] v;
    }

    void empilhar(double x){
        if(n == tam){
            tam = tam * 2;
            double *w = new double [tam];
            for(int i = 0; i < n; i++){
                w[i] = v[i];
            }
            delete[] v;
            v = w;
        }
        v[n] = x;
        n++;
    }

    double topo(){
        return v[n-1];
    }

    int tamanho(){
        return n;
    }

    double buscar(double x){
        for(int i = 0; i < n; i++){
            if(v[i] == x){
                return i;
            }
        }
        
        return -1;
    }

    double desimpilhar(){
        if(n == (tam/4)){
            tam = tam / 2;
            double *w = new double [tam];
            for(int i = 0; i < n; i++){
                w[i] = v[i];
            }
            delete[] v;
            v = w;
        }
        double elemento = topo();
        n--;
        return elemento;
    }

    void mostrar(){
        cout << "Pilha: ";
        for(int i = 0; i < n; i++){
            cout << v[i] << " ";
        }
        cout << "\n";
    }

};
    class fila{
        pilha pilha1;
        pilha pilha2;
        public:

    void enfilar(double x){
        pilha1.empilhar(x);
    }

    double desinfilar(){
        if(pilha2.tamanho() == 0){
            while(pilha1.tamanho() > 0){
                pilha2.empilhar(pilha1.desimpilhar());
            }
        }
        if(pilha2.tamanho() == 0){
            cout << "A fila estah vazia\n";
            return 0;
        }
        return pilha2.desimpilhar();
    }
    void mostrar(){
        pilha1.mostrar();
        pilha2.mostrar();
    }

    double busca(double x){
        
        if(pilha1.buscar(x) == -1 and pilha2.buscar(x) != -1){
            return pilha2.buscar(x);
        }
        else if(pilha1.buscar(x) == -1 and pilha2.buscar(x) == -1){
            return -1;
        }
        else if(pilha1.buscar(x) != -1 and pilha2.buscar(x) != -1){
            return pilha1.buscar(x);
        }
        else if (pilha1.buscar(x) != -1 and pilha2.buscar(x) == -1){
            return pilha1.buscar(x);
        }
        return pilha1.buscar(x) and pilha2.buscar(x);
    }

    };

int main (){
    fila f;
    try{
        while(true){
            int op;
            cout << "Digite 1 para enfilar, 2 para desinfilar, 3 para mostrar, 4 para buscar, 0 para parar: ";
            cin >> op;

            if(op == 1){
                int x;
                cout << "Digite o valor para enfilar\n";
                cin >> x;
                f.enfilar(x);
            }
            if(op == 2){
                f.desinfilar();
            }
            if(op == 3){
                f.mostrar();
            }
            if(op == 4){
                double x;
                cout << "Digite o valor que deseja buscar\n";
                cin >> x;
                if(f.busca(x) == -1){
                    cout << "Valor nao esta na fila";
                }
                else{
                    cout << "O valor " << x << " estah na posicao: " << f.busca(x) << "\n";
                }
            }
            if(op == 0){
                cout<<"Programa encerrado\n";
                break;
            }
        }
    }
    catch(const bad_alloc &e){
        cout << "Deu erro glr\n";
        return 1;
    }
}