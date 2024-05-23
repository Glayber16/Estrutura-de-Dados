#include <iostream>

using namespace std;

int main () {
    int tam = 7;
    int n = tam - 1;
    int j;
    double *v = new double [tam];
    for(int i = 0; i<tam; i++){
        int num;
        cin >> num;
        v[i] = num;
    }
    for (int i = 0; i < tam; i++) {
        // cout << " Os valores do vetor: ";
        cout << v[i] << "\n";
    }
    for(int i = 0; i < tam/2; i++){
        j = v[i];
        v[i] = v[n];
        v[n] = j;
        n--;
        
    }
    for (int i = 0; i < tam; i++) {
        // cout << " Os valores do vetor: ";
        cout << v[i] << '\n';
    }
}