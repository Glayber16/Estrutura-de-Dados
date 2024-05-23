#include <iostream>
#include <new>

using namespace std;

class matriz{
    int i;
    int j;
    double *v;

    public:

    matriz(int linhas, int colunas){
        v = new double [linhas + colunas];
        i = linhas;
        j = colunas;
        
    }

    ~matriz(){
        delete[] v;
    }

    int linha(){
        return i;
    }

    int coluna(){
        return j;
    }

    void montar(double x){
        for(int l = 0; i < linha(); l++){
            for(int k = 0; i < coluna(); k++){
                v[coluna() * j + linha()] = x;
            }
        }
    }

    double valor(){
        return v[coluna()*j + linha()];
    }

    void imprimir(){
        for(int l = 0; l < i; l++){
            cout << "[ ";
            for(int k = 0; k < j; k++){
                cout << valor() << " ";
            }
            cout << "] \n";
        }
        
    }
};


int main () {
    int l;
    int c;
    cout << "Digite respectivamente o numero de linhas e colunas\n";
    cin >> l;
    cin >> c;
    matriz m(l,c);
    m.imprimir();
    for(int l = 0; i < m.linha(); l++){
            for(int k = 0; i < m.coluna(); k++){
                v[m.coluna() * c + m.linha()] = x;
            }
        }
    
}