#include <iostream>

using namespace std;

int main () {
    double media, soma;
    double menos, mais;
    double desvio;
    double valor[5];

    for (int i = 0; i < 5; i++){
        cout << "Digite o " << i + 1 << " valor \n";
        cin >> valor[i];
        soma = valor[i] + soma;
        media = soma/5;
    }

    cout << media << "\n";

    for (int i = 0; i < 5; i++){
        menos = valor[i] - media;
        
        if(menos < 0){
            menos = menos * (-1);
        }
    
        mais = mais + menos;
        desvio = mais/5;

    }

    cout << desvio << "\n";
}