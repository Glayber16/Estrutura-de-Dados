#include <iostream>

using namespace std;

int par(){
    int num, som = 0;
    
   
    while(num > 0){
        cout << "Digite um numero negativo para parar \n";
        cin >> num;
        if(num % 2 == 0){
            som = som + num;
        }
       
    } 
    return som;
}


int main (){
    int num, som = 0;
    cout << " Digite numeros inteiros \n";
    cin >> num;
     if(num % 2 == 0){
        som = num;
    }
    // while(num > 0){
    //     cout << "Digite um numero negativo para parar \n";
    //     cin >> num;
    //     if(num % 2 == 0){
    //         som = som + num;
    //     }
    //     cout << " O resultado :" << som << '\n';
    // }
    int result = par() + som;
    cout << result;
}