#include <iostream>

using namespace std;


class Pilha {
    int tam;
    double *vetor;
    int n;

    public:

    Pilha(){
        tam = 1;
        vetor = new double [tam];
        n = 0;
    }

   void empilhar(double x){
        if(n == tam){
            tam = tam * 2;
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
    
    bool vazia(){
        if(n==0){
            return true;
        }
        else
        return false;
    }

    void mostra(){
        for(int i = 0; i < n; i++){
            cout << "Conteudo " << i << " da Pilha\n"; 
            cout << vetor[i] << "\n";
        }
    }
    int tama(){
        return tam;
    }
    void desimpilhar(){
        if(vazia() == false){
            n--;
            if(n == (tam/4)){
                tam = (tam/2);
                double *w = new double [tam];
                for(int i = 0; i < n; i++){
                    w[i] = vetor[i];
                }
                delete[] vetor;
                vetor = w;
            }
        }
    }
    double desimpilhar_ret(){
         if(vazia() == false){
        double elemento = topo();
        n--;
        return elemento;
    }
    }
    void tamanho(){
        cout << "A quantidade de elementos na pilha: " << n << "\n";
    }
    int topo(){
        return vetor[n-1];
    }

};

int main (){
    Pilha v;
    while(true){
        int seletor;
        cout << "Digite 1 para empilhar, 2 para desimpilhar,  3 para mostrar, 4 para ver o tamanho do vetor, 5 pra ver tamanho da pilha, 6 pra ver o topo, 0 para parar \n";
        cin >> seletor;
       
        if( seletor == 0){
            break;
        }
        if( seletor == 1){
             double x;
            cout << "Digite o valor para ser empilhado \n";
            cin >> x;
            v.empilhar(x);
        }
        if(seletor == 2){
            v.desimpilhar();
        }
        if(seletor == 3){
           v.mostra(); 
        }
        if(seletor == 4){
            cout << v.tama() << "\n";
        }
        if(seletor == 5){
            v.tamanho();
        }
        if(seletor == 6){
            cout << v.topo() << "\n";
        }
        
        
    }
}