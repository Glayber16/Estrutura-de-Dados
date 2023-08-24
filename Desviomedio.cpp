#include <iostream>

using namespace std;

int main () {
    double media, soma;
    double menos, mais;
    double desvio;
    int n;
    cout << "Digite o tamanho do vetor \n"; 
    
    cin >> n;
    double valor[n];

    for (int i = 0; i < n; i++){
        cout << "Digite o " << i + 1 << " valor \n";
        cin >> valor[i];
        soma = valor[i] + soma;
        media = soma/n;
    }

    cout << media << "\n";

    for (int i = 0; i < n; i++){
        menos = valor[i] - media;
        
        if(menos < 0){
            menos = menos * (-1);
        }
    
        mais = mais + menos;
        desvio = mais/n;

    }

    cout << desvio << "\n";
}