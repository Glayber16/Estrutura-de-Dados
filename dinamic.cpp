#include <iostream>
#include <new>

using namespace std;

int main () {
    try{
        int tam = 1;
        int n = 0;
        double *v = new double [tam];
        while(true) {
            int num;
            cin >> num;
            if(num < 0){
                break;
            }
            else{
                if(n == tam) {
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
        }
        for(int i = 0; i < tam; i++){
            cout << " " << v[i] << " ";
        }
    }
    catch (const bad_alloc &execao){
        cout<< "falha na alocacao\n";
        return 1;
    }
}