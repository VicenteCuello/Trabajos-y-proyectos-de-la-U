#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <list>
#include <set>
#include <algorithm>
#include <queue> // Para la cola de prioridad

using namespace std;

struct Graph {
    int V;
    list<int> *adj;
};

Graph createGraph(int V) {
    Graph graph;
    graph.V = V;
    graph.adj = new list<int>[V];
    return graph;
}

void deleteGraph(Graph &graph) {
    delete[] graph.adj;
}

void addEdge(Graph &graph, int v, int w) {
    graph.adj[v].push_back(w);
    graph.adj[w].push_back(v);
}

vector<int> vertexCoverApprox(const Graph &graph) {
    vector<int> vertexCover;
    vector<bool> visited(graph.V, false);

    for (int u = 0; u < graph.V; u++) {
        if (!visited[u]) {
            for (auto v : graph.adj[u]) {
                if (!visited[v]) {
                    visited[u] = true;
                    visited[v] = true;
                    vertexCover.push_back(u);
                    vertexCover.push_back(v);
                    break;
                }
            }
        }
    }

    return vertexCover;
}

vector<int> vertexCoverHeuristic(const Graph &graph) {
    vector<int> vertexCover;
    vector<int> degree(graph.V, 0);
    priority_queue<pair<int, int>> maxHeap; // Par (grado, vértice)

    for (int i = 0; i < graph.V; i++) {
        degree[i] = graph.adj[i].size();
        if (degree[i] > 0) {
            maxHeap.push({degree[i], i});
        }
    }

    vector<bool> inCover(graph.V, false);
    while (!maxHeap.empty()) {
        int v = maxHeap.top().second;
        maxHeap.pop();

        if (degree[v] == 0 || inCover[v]) {
            continue;
        }

        vertexCover.push_back(v);
        inCover[v] = true;

        for (auto u : graph.adj[v]) {
            if (!inCover[u]) {
                degree[u]--;
                maxHeap.push({degree[u], u});
            }
        }
        degree[v] = 0;
    }

    return vertexCover;
}

Graph loadGraphFromFile(const string &filename) {
    ifstream file(filename);

    if (!file.is_open()) {
        cerr << "Error: No se pudo abrir el archivo " << filename << endl;
        exit(EXIT_FAILURE);
    }

    string line;
    int u, v, V = 0;
    set<pair<int, int>> edges;

    while (getline(file, line)) {
        istringstream iss(line);
        if (!(iss >> u >> v)) { break; }
        if (u > v) swap(u, v); // Asegurar que (u, v) siempre tenga u < v
        edges.insert({u - 1, v - 1});
        V = max(V, max(u, v));
    }

    file.close();

    Graph graph = createGraph(V);
    for (auto &edge : edges) {
        addEdge(graph, edge.first, edge.second);
    }
    cout << "Grafo cargado desde " << filename << ": Vertices = " << V << ", Aristas = " << edges.size() << endl;
    return graph;
}

int main() {
    Graph g1 = loadGraphFromFile("grafo1.txt");
    //Graph g2 = loadGraphFromFile("grafo2.txt");
    //Graph g3 = loadGraphFromFile("grafo3.txt");

    vector<int> vcA1 = vertexCoverApprox(g1);
    //vector<int> vcA2 = vertexCoverApprox(g2);
    //vector<int> vcA3 = vertexCoverApprox(g3);
    vector<int> vcB1 = vertexCoverHeuristic(g1);
    //vector<int> vcB2 = vertexCoverHeuristic(g2);
    //vector<int> vcB3 = vertexCoverHeuristic(g3);

    cout << "Resultado para grafo1:" << endl;
    cout << "Estrategia A (Vertex-Cover aproximado): " << vcA1.size() << " vertices" << endl;
    cout << "Estrategia B (Heuristica de mayor grado): " << vcB1.size() << " vertices" << endl;
    cout << endl;

    /*cout << "Resultado para grafo2:" << endl;
    cout << "Estrategia A (Vertex-Cover aproximado): " << vcA2.size() << " vertices" << endl;
    cout << "Estrategia B (Heuristica de mayor grado): " << vcB2.size() << " vertices" << endl;
    cout << endl;

    cout << "Resultado para grafo3:" << endl;
    cout << "Estrategia A (Vertex-Cover aproximado): " << vcA3.size() << " vertices" << endl;
    cout << "Estrategia B (Heuristica de mayor grado): " << vcB3.size() << " vertices" << endl;
    cout << endl;*/

    deleteGraph(g1);
    //deleteGraph(g2);
    //deleteGraph(g3);

    return 0;
}
