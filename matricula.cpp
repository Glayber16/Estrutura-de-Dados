#include <iostream>

using namespace std;



struct aluno{
    double *v;
    int tam;
    int n;
    int matricula;
    int media;

    aluno(){
        cout << "Construtor\n";
        v = new double [1];
        tam = 1;
        n = 0;
        matricula = 0;
        media = 0;
    }

    ~aluno(){
        cout<< "Destrutor\n";
        delete[] v;
    }
  
};

int main () {
    cout << "antes de inicializar\n";
    aluno vet;
    cout << "Depois de inicializar\n";
}