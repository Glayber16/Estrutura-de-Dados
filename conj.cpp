#include <iostream>
#include <new>

using namespace std;

int procurar (double *v, int n, double x){
    for(int i = 0; i < n; i++){
        if(v[i] == x){
            return i;
        }
    }
    return -1;
}


int main () {
    try{
        int tam = 1;
        int n = 0;
        double *v = new double [tam];
        while(true){
            int ac;
            cin >> ac;
            int valor;
            if(ac == 1){
                cout<< "Inserir escolhido\n";
                cin >> valor;
                int pr = procurar(v,n,valor);
                if(pr < 0){
                    if(tam == n) {
                        int novo = tam * 2;
                        double *w = new double [novo];
                        for(int i = 0; i< n; i++){
                            w[i] = v[i];
                        }
                    delete[] v;
                    v = w;
                    tam = novo;
                    }
                    v[n] = valor;
                    n++;
                }
                else{
                    cout << "Nao e possivel repetido\n";
                }
            }
            if(ac==2){
                cout << "Remocao escolhida\n";
                cin >> valor;
                int pr = procurar(v,n,valor);
                if(pr < 0){
                    cout<< "Valor n encontrado\n";
                }
                else{
                    for(int i = pr; i<n; i++){
                        v[i-1] = v[i];
                    }
                    n--;
                    tam--;
                }
            }

            if(ac==3){
                for(int i = 0; i < n; i++){
                    cout << " Valores do vetor "
                    << v[i] << "\n";
                }
            }
            
            if(ac==4) {
                cout << "Encerrando\n";
                break;
            }
        }
    }
    catch(const bad_alloc &excecao){
        cout<<"Deu ruim\n";
        return 1;
    }
}
