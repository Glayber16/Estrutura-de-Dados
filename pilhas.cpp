#include <iostream>
#include <new>
#include <string>

using namespace std;

class pilha{

    int tam;
    string *v;
    int n;

    public:

    pilha(){
        tam = 1;
        v = new string [tam];
        n = 0;
    }

    void empilhar(string s){
        if(n == tam){
            tam = tam * 2;
            string *w = new string [tam];
            for(int i = 0; i < n; i++){
                w[i] = v[i];
            }
            delete[] v;
            v = w;
        }
        v[n] = s;
        n++;
    }
    
    string topo(){
        return v[n-1];
    }

    string desimpilhar(){
        if(n == tam/4){
            tam = tam / 2;
            string *w = new string [tam];
            for(int i = 0; i < n; i++){
                w[i] = v[i];
            }
            delete[] v;
            v = w;
        }
        string elemento = topo();
        n--;
        return elemento;
    }

    void desimpilhar_sem_retorno(){
        n--;
    }

    int tamanho (){
        return n;
    }

    ~pilha(){
        delete[] v;
    }
    
};

double ler(){
    pilha pilha;
    string linha;
    getline(cin, linha);
   
    while(true){
        string palavra;
        getline(cin, palavra);
        if(palavra != "(" and palavra != ")"){
            pilha.empilhar(palavra);
        }
        else{
            if(palavra == ")"){
                double dir = stod(pilha.desimpilhar());
                string op = pilha.desimpilhar();
                double esq = stod(pilha.desimpilhar());
                double res;
                if(op == "+"){
                    res = esq + dir;
                }
                if(op == "-"){
                    res = esq - dir;
                }
                if(op == "*"){
                    res = esq * dir;
                }
                else{
                    res = esq / dir;
                }
                pilha.empilhar(to_string(res));
            }
        }
    }
    return stod(pilha.desimpilhar());
}

int main (){
    try{
        cout << "Digite sua expressão\n";
        double resultado = ler();
        cout << "Resultado = " << resultado;
    }
    catch(const bad_alloc &e){
        cout<< "Deu erro \n";
        return 1;
    }
}