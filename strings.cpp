#include <iostream>
#include <new>
#include <string>

using namespace std;

double ler(){
    string palavra;
    cin >> palavra;
    if(palavra[0] == '('){
        double esq = ler();
        string op;
        cin >> op;
        double dir = ler();
        string dop;
        cin >> dop;
        if(op == "+"){
            return esq + dir;
        }
        else if(op == "-"){
            return esq - dir;
        }
        else if(op == "*"){
            return esq * dir;
        }
        else {
            return esq / dir;
        }
    }
    else return stod(palavra);
}


int main(){
    cout << "Digite a expressao \n";
    double result = ler();
    cout << " Resultado \n" << result;
}