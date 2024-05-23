#include <iostream>
#include <new>

using namespace std;

void ordempar(int *v, int n){
    int par;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(v[j] > v[i]){
                if (v[i] % 2 == 0 and v[j] % 2 == 0){
                    par = v[i];
                    v[i] = v[j];
                    v[j] = par;
                    
                }
            }
        }
    }
}

int main () {
    try{
        int n;
        cin >> n;
        int *v = new int [n];
        for(int i = 0; i < n; i++){
            int num;
            cout<< "valor vetor\n";
            cin >> num;
            v[i] = num;
        }
    cout << "sem ordem: ";
    for(int i = 0; i < n; i++){
        cout << " " << v[i];
    }
    ordempar(v,n);
    cout << "\n ordem par: ";
    for(int i = 0; i < n; i++){
        cout << " " << v[i];
    }
}

catch(const bad_alloc &excecao){
    return 1;
}

}