#include <iostream>

using namespace std;

int main (){
    cout << "Digite o tamanho do vetor \n ";
    int m;
    cin >> m;
    
    double v[m];
    double j;
    int n = m - 1;
    for (int i = 0; i < m; i++){
        v[i] = i + 0.1;
        
    }
    for (int i = 0; i < m; i++) {
        cout << "o " << i << " numero do vetor = " << v[i] << ('\n');
    }
    for (int i = 0; i < m/2; i++) {
        j = v[i];
        v[i] = v[n];
        v[n] = j;
        n--;
    }
    
   for (int i = 0; i < m; i++) {
        cout << "Os " << i << " numeros do vetor = " << v[i] << ('\n');
    }

}