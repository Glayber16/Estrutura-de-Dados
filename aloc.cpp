#include <iostream>

using namespace std;

int main () {
    int n, a = 0;
    int ver = 1;

    double *v = new double [ver];
    for(int i = 0;; i++){

        
        cout <<" Digite os valores do vetor ou um negativo para parar: \n";
        cin >> n;

        if(n < 0) {
            break;
        }
        if (a == ver){
            int novo = ver + 1;
            double *p = new double [novo];
            for(int j = 0; j < a; j++) {
                p[j] = v[j];
                delete[] v; 
                v = p;
                ver = novo;
            }
        }
        v[i] = n;
        
        a++;
    }
    a = ver ;
    for(int i = a-1; 0 <= i; i--){
        cout <<"os valores do vetor: " << v[i] << "\n";
    }
   
}