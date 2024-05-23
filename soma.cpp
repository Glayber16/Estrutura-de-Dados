#include <iostream>
#include <new>

using namespace std;

double *soma (double *v, double * w, int n){
    double *s = new double [n];
    for(int i = 0; i < n; i++){
        s[i] = v[i] + w[i];
    }
    return s;
}

int main () {
    try {
        int n;
        cin >> n;
        double *v = new double [n];
        double *w = new double [n];
        for(int i = 0; i < n; i++) {
            cout << "Valor de v \n";
            int num; 
            cin >> num;
            v[i] = num;
        }
        for(int j = 0; j < n; j++){
            cout << "Valor de w \n";
            int num;
            cin >> num;
            w[j] = num;
        }
        double *s = new double [n];
        s = soma(v,w,n);
        for(int i = 0; i<n; i++){
            cout<< "soma" 
            << s[i];
        }
        delete[] v;
        delete[] w;
        delete[] s;
    }
    catch(const bad_alloc &excecao){
        cout<< "Deu ruim\n";
        return 1;
    }
}