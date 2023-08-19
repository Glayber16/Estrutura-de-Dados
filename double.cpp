#include <iostream>

using namespace std;

double med(int &n){
    int i = 0;
    double media, num, soma = 0;
    while (i < n) {
        cout << " Digite os numeros racionais \n";
        cin >> num;
        soma = soma + num;
        media = soma/n;
        i++;
    }
    return media;
}

int main () {
    int n;
    cout << "digite quantos numeros racionais serao lidos \n";
    cin >> n;
    double result = med(n);
    cout << "a media e : \n" << result;

    // while(i<n){
    //     cout << " Digite os numeros racionais \n";
    //     cin >> num;
    //     soma = soma + num;
    //     media = soma/n;
    //     cout << media;
    //     i++;
    // }

}