#include <iostream>

using namespace std;

int procura(double *v, double x, int n){
    for(int i = 0; i < n; i++){
        if(x == v[i]){
            return i;
        }
    }
    return -1;
}

int main () {
    int n;
    cout << "Digite o tamanho do vetor \n";
    cin >> n;
    double v[n];
    double x;
    cout << "Qual valor voce quer saber se tem no vetor \n";
    cin >> x;
    for(int i = 0; i < n; i++){
        v[i] = i * 2;
    }
    int busca = procura(v, x, n);
    if(busca > 0){
        cout << "o valor esta no indice :" << busca;
    }
    else{
        cout << "O valor nao esta no vetor ";
    }
}