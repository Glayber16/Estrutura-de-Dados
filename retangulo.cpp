#include <iostream>

using namespace std;

int retanx(){
    int coordx, i = 0;
    int base = 0;
    while (i < 5){
        cout << "Digite a coordenada x do ponto  " << i+1 << '\n';
        cin >> coordx;
        base = base + coordx;
        i++;
    }
    return base;
}

int retany(){
    int coordy, i = 0;
    int altura = 0;
    while (i < 5){
        cout << "Digite a coordenada y do ponto " << i+1 << '\n';
        cin >> coordy;
        altura = altura + coordy;
        i++;
    }
    return altura;
}

int main () {
    // int coordx, coordy, i = 0;
    int base = retanx(), altura = retany();
    // while (i < 5){
    //     cout << "Digite a coordenada x do ponto  " << i+1 << '\n';
    //     cin >> coordx;
    //     base = base + coordx;
    //     cout << "Digite a coordenada y do ponto " << i+1 << '\n';
    //     cin >> coordy;
    //     altura = altura + coordy;
    //     i++;
    // }

    if (base > altura){
        cout << "Classificacao do retangulo: Largo";
    }
    if (base == altura) {
        cout << "Classificacao do retangulo: Quadrado";
    }
    if (base < altura) {
        cout << "Classificacao do retangulo: Alto";
    }
}