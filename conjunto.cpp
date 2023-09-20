#include <iostream>

using namespace std;

int procura(double *v, int n, int tam){
    for(int i = 0; i < tam; i++){
        if(n == v[i]){
            return i;
        }
    }
    return -1;
}



int main () {
    int tam = 1;
    int a = 0; // verificador de tamanho//
    int ver; // verificador de ação//
    double *v = new double [tam];
    
    while(true){
        cout << "Digite 1 para inserir, 2 para remover e 3 para parar\n";
        cin >> ver;
        
        if(ver == 1){
            int n;
            cout << "Digite o valor que quer inserir \n";
            cin >> n;
            int tr = procura(v,n,tam);
            if(a == tam){
                int novo = tam * 2;
                double *p = new double [novo];
                for(int j = 0; j < a; j++) {
                    p[j] = v[j];
                }
                    delete[] v;
                    v = p;
                    tam = novo;
            }
            if(tr < 0){
                v[a] = n; 
                a++;
            }
            else{
                cout << "Nao pode numero repetido\n";
            }
            
                
        }
        
        if(ver == 2){
           int n;
            cout << "Digite o valor que quer remover \n";
            cin >> n;
            int tr = procura(v,n,tam);
            if(tr < 0){
                cout << "nao e possivel remover se nao estiver no conjunto\n";
            }
            else{
                
                for(int i = tr + 1; i < tam; i++){
                    v[i - 1] = v[i];
                }
                
                a--;
            }
                
            
            
        }
                
        if(ver == 3) {
           cout << "Todos os valores do programa abaixo \n";
            for(int i = 0; i < a; i++){
                cout << "valor: " << i << " do vetor = " << v[i] << "\n";
            } 
            cout << "Encerramento do programa\n";
            break;
        }

        for(int k = 0; k < a; k++){
            cout << "Conteudo do conjunto na posicao "<< k << ": " << v[k] << "\n";
        }

    }
    delete[] v;
}
