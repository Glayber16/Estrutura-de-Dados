#include <iostream>
#include <new>

using namespace std;

struct vetor{
    double *v;
    int n;
    int tam;

    vetor (){
        cout << "Construtor\n";
        v = new double [1];
        tam = 1;
        n = 0;
    }

    ~vetor(){
        cout << "Destrutor\n";
        delete[] v;
    }

    void inserir (double num){
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

    void imprimir (){
        for(int i = 0; i < n; i++){
            cout<< v[i] << "\n";
        }
    }

    int procurar (double num){
        for(int i = 0; i < n; i++){
            if(v[i] == num){
                return i;
            }
        }
        return -1;
    }
};

int main () {
    try{
        vetor vet;
        while(true) {
            cout<< "Digite 0 pra parar\n";
            double num;
            cin >> num;
            if(num == 0){
                break;
            }
            int look = vet.procurar(num);
            if(look < 0){
                vet.inserir(num);
            }
            else{
                cout<<"nao insira repetidos\n";
            }
            
        }
        vet.imprimir();
    }
    catch(const bad_alloc &excecao){
        cout<< "Deu erro glr\n";
        return 1;
    }
}