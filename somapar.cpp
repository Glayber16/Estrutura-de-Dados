#include <iostream>

using namespace std;

int main () {
    int num;
    int soma = 0;
    while(true){
        cin >> num;
        if(num <0){
            break;
        }
        else{
            if(num % 2 == 0){
                soma = soma +num;
            }
        }
    }
    cout << "sua soma de pares eh: " << soma;
}