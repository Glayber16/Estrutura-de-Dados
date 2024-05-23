#include <iostream>
#include <new>
#include <string>

using namespace std;

class fila {

    int tam;
    double *v;
    int n;

    public:

    fila(){
        tam = 1;
        v = new double [tam];
        n = 0;
    }

    void enfilar(double x){
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

    void desinfilar(){
        for(int i = 0; i < n-1; i++){
            v[i] = v[i+1];
        }
        n--;
    }
    void printar(){
        cout << "Fila: \n";
        for(int i = 0; i < n; i++){
            cout << v[i] << " ";
        }
        cout << "\n";
    }
};

int main (){
    fila fila;
    while(true){
        int op;
        cout << "1 para enfilar, 2 para desinfilar, 3 para printar, 0 para parar \n";
        cin >> op;
        if(op == 1){
            double x;
            cout << "Digite o valor pra ser enfilado\n";
            cin >> x;
            fila.enfilar(x);
        }
        if(op == 2){
            fila.desinfilar();
        }
        if(op == 3){
            fila.printar();
        }
        if(op == 0){
            cout << "Fim do programa\n";
            break;
        }
    }
}