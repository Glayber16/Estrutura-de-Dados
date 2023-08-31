#include <iostream>

using namespace std;

int main () {
    int n, a;
    int ver = 1;

    double *v = new double [ver];
    for(int i = 0;; i++){
        
        
        cout <<" Digite os valores do vetor\n";
        cin >> n;
        if(n < 0) {
            break;
        }
        v[i] = n;
         
        
        
    ver++;
    }
    a = ver -1 ;
    for(int i = a-1; 0 <= i; i--){
        cout <<"os valores do vetor: " << v[i] << "\n";
    }
   
}