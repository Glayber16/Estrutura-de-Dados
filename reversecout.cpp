#include <iostream>

using namespace std;


int main () {
    int n;
    cout << "Digite o tamanho do vetor\n";
    do{
        cin >> n;
     } while(n<=0);

    double *v = new double [n];
    for(int i = 0; i<n; i++){
        cout << "Digite os valores do vetor\n";
        cin >> v[i];
    }
    for(int i = n -1; i>=0; i--){
        cout << v[i] << "\n";
    }
}