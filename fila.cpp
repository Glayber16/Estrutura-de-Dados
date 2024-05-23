#include <iostream>

using namespace std;

class fila{
    int tam;
    double *vetor;
    int n;

    public:

    fila(){
        tam = 1;
        vetor = new double [tam];
        n = 0;
    }

    void enfileirar(double x){
        if(n == tam){
            tam = (tam *2);
            double *w = new double [tam];
            for(int i = 0; i < n; i++){
                w[i] = vetor[i];
            }
            delete[] vetor;
            vetor = w;
        }
        vetor[n] = x;
        n++;
    }

    void desinfilar(){
        for(int i = 0; i < n-1; i++){
            vetor[i] = vetor[i+1];
        }
        n--;
    }

    void mostra(){
        for (int i = 0; i < n; i++){
            cout<< vetor[i] << "\n";
        }
    }

    void tamanho(){
        cout << "O tamanho do vetor: " << tam << "\n";
    }

    void filado(){
        cout << "O tamanho da fila: " << n << "\n";
    }

    double primeiro(){
        return vetor[0];
    }

    ~fila(){
        delete[] vetor;
    }
};


int main (){
    fila v;
    while(true){
        int seletor;
        cout << "Digite 1 para enfileirar, 2 para desinfilar,  3 para mostrar, 4 para ver o tamanho do vetor, 5 pra ver tamanho da pilha, 6 pra ver o topo, 0 para parar \n";
        cin >> seletor;
       
        if( seletor == 0){
            break;
        }
        if( seletor == 1){
             double x;
            cout << "Digite o valor para ser enfileirado \n";
            cin >> x;
            v.enfileirar(x);
        }
        if(seletor == 2){
            v.desinfilar();
        }
        if(seletor == 3){
            v.mostra();
        }
        if(seletor == 4){
            v.tamanho();
        }      
        if(seletor == 5){
            v.filado();
        }
        if(seletor == 6){
            cout << "o primeiro eh: " << v.primeiro() << "\n";
        }
}
}