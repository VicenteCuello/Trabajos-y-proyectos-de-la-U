#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <list>
#include <set>
#include <algorithm>
#include <queue>

using namespace std;

struct Grafo {
    int V;
    list<int> *ady;
};

Grafo crearGrafo(int V) {
    Grafo grafo;
    grafo.V = V;
    grafo.ady = new list<int>[V];
    return grafo;
}

void eliminarGrafo(Grafo &grafo) {
    delete[] grafo.ady;
}

void agregarArista(Grafo &grafo, int v, int w) {
    grafo.ady[v].push_back(w);
    grafo.ady[w].push_back(v);
}

vector<int> VertexCoverA(const Grafo &grafo) {
    vector<int> coberturaDeVertices;
    vector<bool> visitado(grafo.V, false);

    for (int u = 0; u < grafo.V; u++) {
        if (!visitado[u]) {
            for (auto v : grafo.ady[u]) {
                if (!visitado[v]) {
                    visitado[u] = true;
                    visitado[v] = true;
                    coberturaDeVertices.push_back(u);
                    coberturaDeVertices.push_back(v);
                    break;
                }
            }
        }
    }

    return coberturaDeVertices;
}

vector<int> VertexCoverB(const Grafo &grafo) {
    vector<int> coberturaDeVertices;
    vector<list<int>> ady = vector<list<int>>(grafo.ady, grafo.ady + grafo.V); // Copia de la lista de adyacencias
    vector<int> grado(grafo.V, 0);

    // Inicializar los grados de cada vértice
    for (int u = 0; u < grafo.V; ++u) {
        grado[u] = ady[u].size();
    }

    // Mientras haya aristas en el grafo
    while (true) {
        // Encontrar el vértice con el mayor grado
        int maxGrado = -1;
        int v = -1;
        for (int i = 0; i < grafo.V; ++i) {
            if (grado[i] > maxGrado) {
                maxGrado = grado[i];
                v = i;
            }
        }

        // Si no hay más aristas, salimos del bucle
        if (maxGrado == 0) {
            break;
        }

        // Agregar el vértice v a la cobertura de vértices
        coberturaDeVertices.push_back(v);

        // Eliminar todas las aristas conectadas a v
        for (int u : ady[v]) {
            ady[u].remove(v);
            --grado[u];
        }
        ady[v].clear();
        grado[v] = 0;
    }

    return coberturaDeVertices;
}

Grafo cargarGrafoDesdeArchivo(const string &nombreArchivo) {
    ifstream archivo(nombreArchivo);

    if (!archivo.is_open()) {
        cerr << "No se pudo abrir el archivo " << nombreArchivo << endl;
        exit(EXIT_FAILURE);
    }

    string linea;
    int u, v, V = 0;
    set<pair<int, int>> aristas;

    while (getline(archivo, linea)) {
        istringstream iss(linea);
        if (!(iss >> u >> v)) { break; }
        if (u > v){ 
            swap(u, v);
        }
        aristas.insert({u - 1, v - 1});
        V = max(V, max(u, v));
    }

    archivo.close();

    Grafo grafo = crearGrafo(V);
    cout << endl;
    for (auto &arista : aristas) {
        agregarArista(grafo, arista.first, arista.second);
    }
    cout << nombreArchivo << ": Numero de vertices = " << V << ", Numero de aristas = " << aristas.size() << endl;
    cout << endl;
    return grafo;
}

int main() {
    Grafo g1 = cargarGrafoDesdeArchivo("grafo1.txt");
    Grafo g2 = cargarGrafoDesdeArchivo("grafo2.txt");
    Grafo gB = cargarGrafoDesdeArchivo("grafo_b.txt");

    vector<int> vcA1 = VertexCoverA(g1);
    vector<int> vcA2 = VertexCoverA(g2);
    vector<int> vcAt = VertexCoverA(gB);

    vector<int> vcB1 = VertexCoverB(g1);
    vector<int> vcB2 = VertexCoverB(g2);
    vector<int> vcBt = VertexCoverB(gB);

    cout << "Grafo1:" << endl;
    cout << "Estrategia A : " << vcA1.size() << " vertices" << endl;
    cout << "Estrategia B : " << vcB1.size() << " vertices" << endl;
    cout << endl;

    cout << "Grafo2:" << endl;
    cout << "Estrategia A : " << vcA2.size() << " vertices" << endl;
    cout << "Estrategia B : " << vcB2.size() << " vertices" << endl;
    cout << endl;

    cout << "Grafo Bipartito:" << endl;
    cout << "Estrategia A : " << vcAt.size() << " vertices" << endl;
    cout << "Estrategia B : " << vcBt.size() << " vertices" << endl;
    cout << endl;

    eliminarGrafo(g1);
    eliminarGrafo(g2);
    eliminarGrafo(gB);

    return 0;
}
