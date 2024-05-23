#include <iostream>
#include <new>

using namespace std;

class Conjunto{

    int tam;
    double *v;
    int n;
    
    public:

    Conjunto(){
        tam = 1;
        v = new double [tam];
        n = 0;
    }

    void ordena(){
        int maior;
        for(int i = 0; i < n; i++){
            for(int j = i; j < n; j++){
                if(v[j] < v[i]){
                maior = v[i];
                v[i] = v[j];
                v[j] = maior;
            }
        }
        }
        }
    
    int buscabi(double x){
        ordena();
        int ini = 0;
        int fim = n;
        while(ini <= fim){
            int meio = ini + ((fim-ini)/2);
            if(x == v[meio]){
                return meio;
            }
            if(x < v[meio]){
                fim = meio - 1;
            }
            else{
                ini = meio + 1;
            }
        }
        return -1;
    }

    bool pertence(double x){
        if(buscabi(x) == -1){
            return false;
        }
        else{
            return true;
        }
    }

    void insere(double x){
        if(pertence(x) == false){
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
        else{
            cout << "Nao pode elementos repetidos\n";
        }        
        
       
        
    }

    void remove(double x){
        if(pertence(x) == true){
        for(int i = buscabi(x); i < n; i++){
            v[i] = v[i+1];
        }
        n--;
    }
    else{
        cout << "Nao eh possivel remover elementos que nao estejam no conjunto\n";
    }
    }
    void mostra(){
        cout << "Conjunto: ";
        for(int i = 0; i < n; i++){
            cout << v[i] << " ";
        }
        cout << "\n";
    }
    ~Conjunto(){
        delete[] v;
    }

};

int main (){
    Conjunto conj;
    while(true){
        int op;
        cout<< "\n0 para parar, 1 para inserir, 2 para remover, 3 para printar, 4 para buscar\n";
        cin >> op;
        if(op == 1){
            double x;
            cout << "Digite o valor para inserir no conjunto \n";
            cin >> x;
            conj.insere(x);
        }
        if(op == 2){
            double x;
            cout << "Digite o valor para remover no conjunto \n";
            cin >> x;
            conj.remove(x);
        }
        if(op == 3){
            conj.mostra();
        }
        if(op == 4){
            double x;
            cout << "Digite o valor que deseja buscar no conjunto: ";
            cin >> x;
            if(conj.pertence(x) == true){
                cout << "O elemento está na posição: " << conj.buscabi(x);
            }
            else{
                cout << "Elemento nao esta no conjunto ";
            }
        }
        if(op == 0){
            cout << "Programa encerrado";
            break;
        }
    }
}