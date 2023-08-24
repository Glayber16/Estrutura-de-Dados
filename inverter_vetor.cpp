#include <iostream>

using namespace std;

int main (){
    double v[7];
    double j;
    int n = 6;
    for (int i = 0; i < 7; i++){
        v[i] = i + 0.1;
        
    }
    for (int i = 0; i < 7; i++) {
        cout << "o " << i << " numero do vetor = " << v[i] << ('\n');
    }
    for (int i = 0; i < 7; i++) {
        j = v[i];
        v[i] = v[n - i];
        v[n - i] = j;

        cout << "Os " << i << " numeros do vetor = " << v[i] << ('\n');
    }
   

}