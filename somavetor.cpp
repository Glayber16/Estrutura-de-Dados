#include <iostream>

using namespace std;

 double* soma (double *v, double *w, int n){
    double *s = new double [n];
    for(int i = 0; i < n; i++){
        s[i] = v[i] + w[i];
    }
    return s;
    delete [] s;
}



int main(){
    int n;
    cout << "Digite o tamanho do vetor: ";
    do
    {
        cin >> n;
    } while (n<0);
    
    double *v = new double [n];
    double *w = new double [n];
    for(int i = 0; i<n; i++){
        cout << "Digite os valores do vetor v: \n";
        cin >> v[i];
    }
    for(int j = 0; j<n; j++){
        cout << "Digite os valores do vetor w: \n";
        cin >> w[j];
    }
   double *s = soma(v,w,n);
   for(int i = 0; i <n; i++){
        cout << "a soma de " << v[i] << " + " << w[i] << " no indice: " << i << " = " << s[i] << "\n";
    }
    delete [] v;
    delete [] w;
    delete [] s;
}

 // double *s = new double [n];
    // for(int i = 0; i < n; i++){
    //     s[i] = v[i] + w[i];
    // }
    