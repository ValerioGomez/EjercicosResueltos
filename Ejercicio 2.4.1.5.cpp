//Listas de Incidencia y Representación geométrica
#include <iostream>
#include <list>

using namespace std;
struct Edge {//arista
    int dest;
    int weight;
};
class Graph {//grafo utilizando listas de incidencia
public:
    int V;
    list<Edge> *adj;  // lista de adyacencia como array
    // constructor para inicializar el grafo con V nodos
    Graph(int V) : V(V) {
        adj = new list<Edge>[V];
    }
    //agregar una arista al grafo
    void addEdge(int src, int dest, int weight = 0) {
        Edge edge = {dest, weight};
        adj[src].push_back(edge);
        /*Si el grafo es no dirigido, descomenta la siguiente línea para agregar la arista en el otro sentido
        Edge reverse_edge = {src, weight};
        adj[dest].push_back(reverse_edge);*/
    }
};
int main() {
    int V = 5;  // Número de nodos
    Graph graph(V);
    graph.addEdge(0, 1);
    graph.addEdge(0, 4);
    graph.addEdge(1, 2);
    graph.addEdge(1, 3);
    graph.addEdge(1, 4);
    graph.addEdge(2, 3);
    graph.addEdge(3, 4);
    for (int i = 0; i < V; i++) {
        cout << "El nodo " << i << " esta conectado a:";
        for (list<Edge>::const_iterator it = graph.adj[i].begin(); it != graph.adj[i].end(); ++it) {
            cout << " -> " << it->dest;
        }
        cout << endl;
    }
    delete[] graph.adj;
    return 0;
}
//Tambien se puede representar como Representacion Geometrica

/*
#include <iostream>
#include <cmath>

using namespace std;
struct Punto {
    double x, y;
    Punto(double x = 0.0, double y = 0.0) : x(x), y(y) {}
};

struct Arista {
    int src, dest;
    Arista(int src = 0, int dest = 0) : src(src), dest(dest) {}
};

class Grafo {
public:
    static const int MAX_PUNTOS = 10; 
    Punto puntos[MAX_PUNTOS];
    Arista aristas[MAX_PUNTOS]; 
    int numPuntos;
    int numAristas;

    Grafo() : numPuntos(0), numAristas(0) {}

    void addPoint(double x, double y) {
        if (numPuntos < MAX_PUNTOS) {
            puntos[numPuntos] = Punto(x, y);
            numPuntos++;
        }
    }

    void addEdge(int src, int dest) {
        if (numAristas < MAX_PUNTOS) {
            aristas[numAristas] = Arista(src, dest);
            numAristas++;
        }
    }
};

int main() {
    Grafo graph;

    graph.addPoint(0.0, 0.0);
    graph.addPoint(1.0, 1.0);
    graph.addPoint(2.0, 0.0);
    graph.addPoint(1.0, 2.0);

    graph.addEdge(0, 1);
    graph.addEdge(1, 2);
    graph.addEdge(2, 3);
    graph.addEdge(3, 0);

    cout << "Puntos en el grafo:" << endl;
    for (int i = 0; i < graph.numPuntos; i++) {
        cout << "Nodo " << i << ": (" << graph.puntos[i].x << ", " << graph.puntos[i].y << ")" << endl;
    }

    cout << "Aristas en el grafo:" << endl;
    for (int i = 0; i < graph.numAristas; i++) {
        cout << "Arista " << i << ": " << graph.aristas[i].src << " -> " << graph.aristas[i].dest << endl;
    }

    return 0;
}

*/