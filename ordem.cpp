#include <iostream>

using namespace std;

void ordena (double *v, int n){
    int maior;
    for(int i = 0; i < n; i++){
        for(int j = i; j < n; j++){
            if(v[i] > v[j]){
                maior = v[i];
                v[i] = v[j];
                v[j] = maior;
            }
        }
    }
}

int main (){
    int n;
    cout << "Digite o tamanho do vetor \n";
    cin >> n;
    double v[n];
    for (int i = 0; i < n; i++){
        cout << "Digite os valores do vetor \n";
        cin >> v[i];
    }
    ordena (v, n);
    for (int i = 0; i < n; i++){
        cout << v[i] << "\n";
        
    }  


}