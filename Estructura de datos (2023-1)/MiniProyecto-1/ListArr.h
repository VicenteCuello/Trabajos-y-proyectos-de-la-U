#include <iostream>
#include <vector>
#include "ListArrADT.h"

using namespace std;

struct NodoLigado{
    private:
        friend struct NodoRes;
        friend class ListArr;
        NodoLigado* next;
        int tam_arreglos;
        int cont;
        int* arr;

    public:
        NodoLigado(int b, NodoLigado* siguiente = nullptr){
            tam_arreglos = b;
            arr = new int[tam_arreglos];
            next = siguiente;
            cont = 0;
        }
        ~NodoLigado(){
            delete[] arr;
        }
};

struct NodoRes{
    private:
        friend struct NodoLigado;
        friend class ListArr;
        int capacidad;
        int cont;
        NodoRes* izq_R;
        NodoRes* der_R;

        NodoLigado* izq_L;
        NodoLigado* der_L;
    public:
        NodoRes(int capacidad, int cont){
            this->capacidad = capacidad;
            this->cont = cont;
        }

};

class ListArr : public ListArrADT{
    private:
        int capacidad;
        int num_nodos;
        int cont;
        NodoLigado* lista_nodos;
        NodoRes* resumenes;

    public:
        ListArr(int b);
        int size();
        void insert_left(int v);
        void insert_right(int v);
        void insert(int v, int i);
        void print();
        bool find(int v);
        void updtNodos(NodoLigado* nodo);
};
