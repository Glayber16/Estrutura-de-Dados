#include <iostream>

using namespace std;

// int procura (double *v, int x, int tam){
//     for(int i = 0; i < tam; i++){
//         if(x == v[i]){
//             return true;
//         }
//     }
// }



int main () {
    bool tr = true; 
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
            
            
            if(a == tam){
                int novo = tam + 1;
                double *p = new double [novo];
                for(int j = 0; j < a; j++) {
                    p[j] = v[j];
                }
                    delete[] v;
                    v = p;
                    tam = novo;
            }
            v[a] = n; 
            a++;
                
        }
        
        if(ver == 2){
           int n;
            cout << "Digite o valor que quer remover \n";
            cin >> n;

            for(int i = 0; i<a; i++){
                if(n == v[i]){
                    for(int j = i; j<a; j++){
                        v[i] = v[i+1];
                    }
                    
                }
            }
             for(int i = 0; i<a; i++){
                if(n != v[i]){
                    cout << "nao pode ser removido\n";
                }
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
            cout << "Conteudo do conjunto: " << v[k] << "\n";
        }

    }

}
