#include "ListArr.h"
#include <iostream>

using namespace std;

int main() {
   // Crear una lista con b = 3
    ListArr lista(3);
    
    // Insertar algunos elementos
    lista.insert_left(44);
    lista.insert_left(5);
    lista.insert(16,2);

    lista.insert_right(14);
    lista.insert(4,1);
    lista.insert_right(63);

    lista.insert_right(7);
    lista.insert_right(21);
    lista.insert(6,7);
    lista.insert_right(10);

    lista.insert(33,9);
    lista.insert_right(9);
    lista.insert_right(11);

    // Imprimir la lista
    lista.print();

    // Imprimir tamaño
    
    cout << "El cantidad de elementos en el ListArr es: " << lista.size() << endl;

    // Buscar algunos elementos
    if (lista.find(3)) {
        cout << "El elemento 3 se encuentra en la lista" << endl;
    } else {
        cout << "El elemento 3 no se encuentra en la lista" << endl;
    }
    if (lista.find(4)) {
        cout << "El elemento 4 se encuentra en la lista" << endl;
    } else {
        cout << "El elemento 4 no se encuentra en la lista" << endl;
    }
    if (lista.find(1)) {
        cout << "El elemento 1 se encuentra en la lista" << endl;
    } else {
        cout << "El elemento 1 no se encuentra en la lista" << endl;
    }

    if (lista.find(9)) {
        cout << "El elemento 9 se encuentra en la lista" << endl;
    } else {
        cout << "El elemento 9 no se encuentra en la lista" << endl;
    }

    if (lista.find(2)) {
        cout << "El elemento 2 se encuentra en la lista" << endl;
    } else {
        cout << "El elemento 2 no se encuentra en la lista" << endl;
    }
    if (lista.find(5)) {
        cout << "El elemento 5 se encuentra en la lista" << endl;
    } else {
        cout << "El elemento 5 no se encuentra en la lista" << endl;
    }
    if (lista.find(7)) {
        cout << "El elemento 7 se encuentra en la lista" << endl;
    } else {
        cout << "El elemento 7 no se encuentra en la lista" << endl;
    }

    return 0;
}
