#include "ListArr.h"
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

ListArr :: ListArr(int capacidad){
    this->capacidad = capacidad;
    num_nodos = 1;
    lista_nodos = new NodoLigado(capacidad);
	resumenes = new NodoRes(2*capacidad, 0);
	resumenes->izq_L = lista_nodos;
}

int ListArr::size() {
    return resumenes->cont;
}

void ListArr::updtNodos(NodoLigado* nodo) {
    int poi = ceil(num_nodos / 2.0);
	vector<NodoRes*> raiz;
	auto it = raiz.begin();
	for (int i = 0; i < poi; i++) {
		NodoRes* n = new NodoRes(2 * capacidad, 0);
		it = raiz.insert(it, n);
		it++;
	}

    NodoLigado* primer_nodo = nodo;
    for (int i = 0; i < poi; i++) {
        raiz.at(i)->izq_L = primer_nodo;
        raiz.at(i)->der_L = primer_nodo->next;
        if (raiz.at(i)->der_L == nullptr) {
            raiz.at(i)->cont = raiz.at(i)->izq_L->cont;
        } else {
            raiz.at(i)->cont = raiz.at(i)->izq_L->cont + raiz.at(i)->der_L->cont;
        }
        if (primer_nodo->next != nullptr) {
            primer_nodo = primer_nodo->next->next;
        }
    }

    vector<NodoRes*> root = raiz;
    while (poi != 1) {
        poi = ceil(poi / 2.0);
		vector<NodoRes*> next(poi, nullptr);
		for (auto it = next.begin(); it != next.end(); ++it) {
			*it = new NodoRes(0, 0);
		}

        for (int i = 0; i < poi; i++) {
            next.at(i)->izq_R = root.at(2 * i);
            if (2 * i + 1 <= next.size()) {
                next.at(i)->der_R = root.at(2 * i + 1);
                next.at(i)->cont = next.at(i)->izq_R->cont + next.at(i)->der_R->cont;
                next.at(i)->capacidad = next.at(i)->izq_R->capacidad * 2;
            } else {
                next.at(i)->cont = next.at(i)->izq_R->cont;
                next.at(i)->capacidad = next.at(i)->izq_R->capacidad * 2;
            }
        }
        root = next;
    }
    resumenes = root.at(0);
}


void ListArr::insert_left(int v){
	this->insert(v, 0);
}

void ListArr::insert_right(int v){
	this->insert(v, this->size());
}

void ListArr::insert(int v, int i){
	try{	
		if(i < 0 || i > resumenes->cont) throw "Indice fuera del vector!";
			NodoRes* res = resumenes;
			while(res->izq_L == nullptr){
				if(i <= res->izq_R->cont){
					res = res->izq_R;
				}else{
					i -= res->izq_R->cont;
					res = res->der_R;
				}                                                                                                     
			}
			NodoLigado* nodo;
			if (i > res->izq_L->cont) {
				i -= res->izq_L->cont;
				nodo = res->der_L;
				} else {
				nodo = res->izq_L;
				}

			if(nodo->cont >= nodo->tam_arreglos){
				if(i != nodo->cont){
					NodoLigado* new_nodo = new NodoLigado(capacidad);
					new_nodo->arr[0] = nodo->arr[capacidad-1];
					new_nodo->cont++;
					num_nodos++;
					for (int j = 0; j < nodo->cont-i ; j++){
					nodo->arr[nodo->cont-j] = nodo->arr[nodo->cont-j-1];
					}
					nodo->arr[i] = v;
					new_nodo->next = nodo->next;
					nodo->next = new_nodo;
				}else{
					NodoLigado* new_nodo = new NodoLigado(capacidad);
					new_nodo->arr[0] = v;
					new_nodo->cont++;
					num_nodos++;
					new_nodo->next = nodo->next;
					nodo->next = new_nodo;
				}
			}else{
				for (int j = 0; j < nodo->cont-i ; j++){
				nodo->arr[nodo->cont-j] = nodo->arr[nodo->cont-j-1];
				}
				nodo->arr[i] = v;
				nodo->cont++;
			}
			updtNodos(lista_nodos);
	}catch(const char* message){
        cerr << message << endl;
        exit(EXIT_FAILURE);
    }
}
void ListArr::print(){
	NodoLigado* nodo = lista_nodos;
	cout << "[";
	while(nodo!= nullptr){
		for(int i=0; i<nodo->cont; i++){
			cout << nodo->arr[i];
			if(i == nodo->cont-1 && nodo->next == nullptr){
				cout << "]"<< endl;
			}else{
				cout << " ";
			}
		}
		nodo = nodo->next;
	}
}

bool ListArr::find(int v) {
    NodoLigado* actual = lista_nodos;
    while (actual != nullptr) {
        for (int i = 0; i < actual->tam_arreglos; i++) {
            if (actual->arr[i] == v) {
                return true;
            }
        }
        actual = actual->next;
    }
    return false;
}