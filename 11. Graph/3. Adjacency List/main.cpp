#include <iostream>
#include <list>
#include <cstring>
using namespace std;

struct Vertex;
struct Edge;

struct Vertex {
    char elem;
    list<Edge*> out; // Outgoing edges
    list<Edge*> inc; // Incoming edges
};

struct Edge {
    Vertex* origin;
    Vertex* destination;
    char elem;
};

class AdjacencyListGraph {
private:
    Vertex vertices[MAX]; // Array of vertices
    Edge edges[MAX];      // Array of edges
    int vertexCount;      // Current count of vertices
    int edgeCount;        // Current count of edges

public:
    AdjacencyListGraph() : vertexCount(0), edgeCount(0) {}

    bool insertVertex(char elem) {
        if (vertexCount >= MAX) return false; // Max vertices reached

        for (int i = 0; i < vertexCount; ++i) {
            if (vertices[i].elem == elem) return false; // Vertex already exists
        }

        vertices[vertexCount++] = {elem};
        return true;
    }

    bool insertEdge(char originElem, char destElem, char elem) {
        if (edgeCount >= MAX) return false; // Max edges reached

        Vertex* origin = nullptr;
        Vertex* destination = nullptr;

        // Find the origin and destination vertices
        for (int i = 0; i < vertexCount; ++i) {
            if (vertices[i].elem == originElem) origin = &vertices[i];
            if (vertices[i].elem == destElem) destination = &vertices[i];
        }

        if (!origin || !destination) return false; // Either vertex not found

        // Create and add the edge
        edges[edgeCount++] = {origin, destination, elem};
        Edge* edge = &edges[edgeCount - 1];

        origin->out.push_back(edge);
        destination->inc.push_back(edge);
        return true;
    }

    void print() {
        std::cout << "Adjacency List:\n";
        for (int i = 0; i < vertexCount; ++i) {
            std::cout << vertices[i].elem << " -> ";
            for (Edge* edge : vertices[i].out) {
                std::cout << "(" << edge->destination->elem << ", " << edge->elem << ") ";
            }
            std::cout << "\n";
        }
    }
};

int main() {
     // Adjacency List Example
    AdjacencyListGraph adjListGraph;
    adjListGraph.insertVertex('A');
    adjListGraph.insertVertex('B');
    adjListGraph.insertVertex('C');
    adjListGraph.insertEdge('A', 'B', 'X');
    adjListGraph.insertEdge('A', 'C', 'Y');
    adjListGraph.print();

    return 0;
}