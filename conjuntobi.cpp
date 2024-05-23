#include <iostream>
#include <new>

using namespace std;

class conjunto{

    int tam;
    double *v;
    int n;

    public:

    conjunto(){
        tam = 1;
        v = new double [tam];
        n = 0;
    }

    ~conjunto(){
        delete[] v;
    }

    void ordenar(){
        double maior;
        for(int i = 0; i < n; i++){
            for(int j = i; j < n; j++){
                if(v[i] > v[j]){
                    maior = v[i];
                    v[i] = v[j];
                    v[j] = maior;
                }
            }
        }
    }

    int buscabi(double x){
        int esq = 0;
        int dir = n-1;
        while(esq <= dir){
            int meio = esq + ((dir - esq) /2);
            if(v[meio] == x){
                return meio;
            }
            else if(v[meio] > x){
                dir = meio - 1;
            }
            else {
                esq = meio + 1;
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
            ordenar();
        }
        else{
            cout << "Elemento repetido\n";
        }
    }

    void remove(double x){
        if(pertence(x) == true){
            if(n == (tam/4)){
                tam = tam /2;
                double *w = new double [tam];
                for(int i = 0; i < n; i++){
                    w[i] = v[i];
                }
                delete[] v;
                v = w;
            }
            for(int i = buscabi(x); i < n; i++){
                v[i] = v[i+1];
            }
            n--;
        }
        else{
            cout << "Valor nao se encontra no conjunto \n";
        }
    }

    void mostra(){
        cout << "Conjunto: ";
        for(int i = 0; i < n; i++){
            cout<< v[i] << " ";
        }
        cout << "\n";
    }

};


int main (){
    conjunto c;
    while(true){
        int op;
        cout << "Digite 1 para inserir, 2 para remover, 3 para mostrar, 4 para buscar, 0 para parar: ";
        cin >> op;

        if(op == 1){
            int x;
            cout << "Digite o valor para inserir\n";
            cin >> x;
            c.insere(x);
    }
        if(op == 2){
            int x;
            cout << "Digite o valor para remover\n";
            cin >> x;
            c.remove(x);
        }
        if(op == 3){
            c.mostra();
        }
        if(op == 4){
            int x;
            cout << "Digite o valor para buscar\n";
            cin >> x;
            if(c.buscabi(x) == -1){
                cout<< "Elemento nao esta no conjunto \n";
            }
            else{
                cout << "elemento esta na posicao: " << c.buscabi(x) << "\n";
            }
        }
        if(op == 0){
            cout << "Programa encerrado\n";
            break;
        }
}

}