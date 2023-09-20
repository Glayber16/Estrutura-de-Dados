#include <iostream>
#include <new>

using namespace std;

struct conjunto{
    double *v;
    int tam;
    int n;

    conjunto(){
        cout << "Construtor\n";
        v = new double [1];
        tam = 1;
        n = 0;
    }
    ~conjunto(){
        cout << "Destrutor";
        delete[] v;
    }

    void inserir(double num){
        if(tam == n){
            int novo = tam *2;
            double *w = new double [novo];
            for(int i = 0; i<n; i++){
                w[i] = v[i];
            }
            delete[] v;
            v = w;
            tam = novo;
        }
        v[n] = num;
        n++;
    }
    int procurar(double num){
        for(int i = 0; i<n; i++){
            if(v[i] == num){
                return i;
            }
        }
        return -1;
    }
    void remover(int j){
        for(int i = j +1; i<n; i++){
            v[i - 1] = v[i];
        }
        n--;
    }
    void imprime(){
        cout << "Os valores do vetor: ";
        for(int i = 0; i<n; i++){
            cout<< " " << v[i];
        }
        cout << "\n";
    }
};

int main() {
    try{
        conjunto conj;
        while(true){
            cout << "1-inserir, 2-remover, 3-printar, 4-parar\n";
            int ac;
            cin >> ac;

            if(ac==1){
                cout << "Digite o valor a ser inserido\n";
                int num;
                cin >> num;
                if(conj.procurar(num) < 0){
                    conj.inserir(num);
                }
                else{
                    cout << "Nao repetir num\n";
                }
            }

            if(ac==2){
                cout << "Digite o valor a ser retirado\n";
                int re;
                cin >> re;
                if(conj.procurar(re) < 0){
                    cout << "Valor nao esta no vetor\n";
                }
                else{
                    conj.remover(conj.procurar(re));
                }
            }
            if(ac==3){
                conj.imprime();
            }
            if(ac==4){
                cout << "encerrando programa\n";
                break;
            }

        }
    }

    catch(const bad_alloc &excecao){
        cout<< "Deu ruim glr\n";
        return 1;
    }
}