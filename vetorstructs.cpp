#include <iostream>
#include <new>

using namespace std;

struct vetor{
    int tam;
    int n;
    double *v;

    vetor(){
        tam = 1;
        n = 0;
        v = new double [1];
    }

    ~vetor() {
        delete[] v;
    }

    void inserir(double num){
        if(n == tam){
            int novo = tam * 2;
            double *w = new double [novo];
            for(int i = 0; i < n; i++){
                w[i] = v[i];
            }
            delete[] v;
            v = w;
            tam = novo;
        }
        v[n] = num;
        n++;
    }

    void imprimir(){
        cout << " Valores do vetor: ";
        for(int i = 0; i < n; i++){
            cout << " " << v[i] << " ";
        }
    }

    int procurar(double num){
        for(int i = 0; i<n; i++){
            if(v[i] == num){
                return i;
            }
        }
        return -1;
    }

};

int main() {
    try{
        vetor vet;
        while(true){
            double num;
            cin >> num;
            if(num < 0){
                vet.imprimir();
                break;
            }
            else{
                int pr = vet.procurar(num);
                if(pr < 0){
                    vet.inserir(num);
                }
                else{
                    cout<<"sem repetido\n";
                }
            }
        }
    }
    catch(const bad_alloc &excecao){
        cout << "Deu ruim";
        return 1;
    }
}