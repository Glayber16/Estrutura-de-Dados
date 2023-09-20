#include <iostream>
#include <new>

using namespace std;

struct conjunto{
    int tam;
    int n;
    double *v;

    conjunto(){
        tam = 1;
        n = 0;
        v = new double [1];
    }

    ~conjunto(){
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

    int procura(double num){
        for(int i = 0; i < n; i++){
            if(v[i] == num){
                return i;
            }
        }
        return -1;
    }
    

    void remover(double num){
        int pr = procura(num);
        for(int i = pr + 1; i<n; i++){
            v[i-1] = v[i];
        }
        n--;
        if(n == tam/4){
            int novo = tam/2;
            double *w = new double [novo];
            for(int i = 0; i < n; i++){
                w[i] = v[i];
            }
            delete[] v;
            v = w;
            tam = novo;
        }
    }

    void imprimir(){
        cout << "Os valores do vetor:";
        for(int i = 0; i < n; i++){
            cout << " " << v[i];
        }
        cout << "\n";
   }
};

int main () {
    try{
        conjunto conj;
        while(true){
            cout << "1-inserir, 2-remover, 3-printar, 4-parar\n";
            int a;
            cin>> a;
            int num;
            if(a==1){
                cout << "Inserir escolhido\n";
                cin >> num;
                int pr = conj.procura(num);
                if(pr < 0){
                    conj.inserir(num);
                }
                else{
                    cout << "Sem numero repetido\n";
                }
            }

            if(a==2){
                cout << "Remocao escolhida\n";
                cin >> num;
                int pr = conj.procura(num);
                if (pr < 0){
                    cout << "Valor nao encontrado\n";
                }
                else{
                    conj.remover(num);
                }
            }

            if(a == 3){
                conj.imprimir();
            }

            if(a == 4){
                cout << "Encerrando o programa";
                break;
            }
        }
    }

   catch(const bad_alloc &excecao){
    cout<< "Falha\n";
    return 1;
   }

}