#include <iostream>
#include <new> 

using namespace std;

int main () {

    int tam = 1;
    int n = 0;

    double *v = new double [tam];
    while(true){
        cout <<" Digite os valores do vetor ou um negativo para parar: \n";

        int i;
        
        cin >> i;

        if(i < 0)  break;
        

        if (n == tam){
            int novo = tam + 1;
            double *p = new double [novo];
            for(int j = 0; j < n; j++) {
                p[j] = v[j];
            }
                delete[] v; 
                v = p;
                tam = novo;
            
        }
                      
            v[n] = i;
            n++;
        
    }


    for(int j = n-1; j >= 0; j--){
        cout <<"os valores do vetor: " << v[j] << "\n";
    }

   delete[] v;
}

// tentar try catch depois//