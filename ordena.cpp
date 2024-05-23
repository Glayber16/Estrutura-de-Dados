#include <iostream>
#include <new>

using namespace std;

int procurar(double *v, int n, double x){
    for(int i = 0; i<n; i++){
        if(v[i] == x){
            return i;
        }
    }
    return -1;
}

void ordenar(double *v, int n) {
    int maior;
    for(int i = 0; i<n; i++){
        for(int j = i; j<n; j++){
            if(v[j] > v[i]){
                maior = v[i];
                v[i] = v[j];
                v[j] = maior;
            }
        }
    }
}

int main () {
    try {
        int tam;
        cin >> tam;
        double *v = new double [tam];
        for(int i = 0; i < tam; i++){
            int num;
            cin >> num;
            v[i] = num;
        }
        int pr;
        cin >> pr;
        if(procurar(v, tam, pr) < 0){
            cout << "Valor n esta no vetor\n";
        }
        else{
            cout << "Valor esta no vetor\n";
        }
        ordenar(v,tam);
        for(int i = 0; i < tam; i++){
            cout<< v[i];
        }
    }
    catch(const bad_alloc &excecao){
        cout<< "Falha na alocacao\n";
        return 1;
    }
}