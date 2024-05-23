#include <iostream>
#include <new>
#include <string>

using namespace std;

class deque{
    int tam;
    double *v;
    int n;
    double esq;
    double dir;

    deque(){
        tam = 1;
        v = new double [tam];
        n = 0;
        esq = v[0];
        dir = v[0];
    }
};
