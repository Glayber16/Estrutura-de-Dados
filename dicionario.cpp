#include <iostream>
#include <new>
#include <string>

using namespace std;

class dicionario{
  public:

    struct aluno{
        string nome;
        int matricula;
    };

    int tam;
    aluno *v;
    int n;


    dicionario(){
        tam = 1;
        v = new aluno [tam];
        n = 0;
    }

    void ordenar(){
        int maior;
        string troca;
        for(int i = 0; i < n; i++){
            for(int j = i; j < n; j++){
                if(v[i].matricula > v[j].matricula){
                    maior = v[i].matricula;
                    v[i].matricula = v[j].matricula;
                    v[j].matricula = maior;
                    troca = v[i].nome;
                    v[i].nome = v[j].nome;
                    v[j].nome = troca; 
                }
            }
        }
    }

    void inserir(int m, string name){
        if(consultar(m) == -1){
        if(n == tam){
            tam = tam * 2;
            aluno *w = new aluno [tam];
            for(int i = 0; i < n; i++){
                w[i].matricula = v[i].matricula;
                w[i].nome = v[i].nome;
            }
            delete[] v;
            v = w;
        }
        v[n].matricula = m;
        v[n].nome = name;
        ordenar();
        n++;
        
        
    }
    else{
        cout << "Chave jah existente\n";
    }
    }

    int consultar(int m){
        int esq = 0;
        int dir = n - 1;
        while(esq <= dir){
            int meio = esq - ((dir - esq)/2);
            if(v[meio].matricula == m){
                return meio;
            }
            else if(v[meio].matricula > m){
                dir = meio - 1;
            }
            else{
                esq = meio + 1;
            }
        }
        return -1;
    }

    void remover(int m){
        if(consultar(m) != -1){
             if(n == tam/4){
            tam = tam / 2;
            aluno *w = new aluno [tam];
            for(int i = 0; i < n; i++){
                w[i].matricula = v[i].matricula;
                w[i].nome = v[i].nome;
            }
            delete[] v;
            v = w;
        }
        for(int i = consultar(m); i < n; i++){
            v[i].matricula = v[i+1].matricula;
            v[i].nome = v[i+1].nome;
        }
        n--;
        }
        else{
            cout << "Aluno nao esta na chamada\n";
        }

    }

    void mostra(){
        cout << "Alunos: \n";
        for(int i = 0; i < n; i++){
            cout << "Matricula: " << v[i].matricula;
            cout << " Nome: " << v[i].nome << "\n";
        }
    }

};

int main() {
    dicionario a;
    while(true){
       int op;
        cout << "Digite 1 para inserir, 2 para remover, 3 para mostrar, 4 para buscar, 0 para parar: ";
        cin >> op;

        if(op == 1){
            int x;
            cout << "Digite a matricula para inserir\n";
            cin >> x;
            string name;;
            cout << "Digite o nome do aluno \n";
            cin >> name;
            a.inserir(x, name);
        }
        if(op == 2){
            int x;
            cout << "Digite a matricula para remover\n";
            cin >> x;
            a.remover(x);
        }
        if(op == 3){
            a.mostra();
        }
        if(op == 4){
            int x;
            cout << "Digite a matricula para buscar\n";
            cin >> x;
            if(a.consultar(x) == -1){
                cout<< "Aluno nao encontrado\n";
            }
            else{
                cout << "Aluno eh o " << a.consultar(x) << "da chamada \n";
            }   
        }
        if(op == 0){
            cout << "Chamada encerrada\n";
            break;
        }
}
}