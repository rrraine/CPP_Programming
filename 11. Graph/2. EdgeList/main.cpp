#include <iostream>
#include <cstring>

const int MAX = 100; // Max vertices or edges

struct Vertex {
    char elem;
};

struct Edge {
    Vertex* origin;
    Vertex* destination;
    char elem;
};

class EdgeListGraph {
private:
    Vertex vertices[MAX];   // Array of vertices
    Edge edges[MAX];        // Array of edges
    int vertexCount;        // Current count of vertices
    int edgeCount;          // Current count of edges

public:
    EdgeListGraph() : vertexCount(0), edgeCount(0) {}

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

        edges[edgeCount++] = {origin, destination, elem};
        return true;
    }

    void print() {
        std::cout << "Vertices: ";
        for (int i = 0; i < vertexCount; ++i) {
            std::cout << vertices[i].elem << " ";
        }
        std::cout << "\nEdges:\n";
        for (int i = 0; i < edgeCount; ++i) {
            std::cout << "(" << edges[i].origin->elem << ", " << edges[i].destination->elem 
                      << ", " << edges[i].elem << ")\n";
        }
    }
};

int main() {
    // Edge List Example
    EdgeListGraph edgeListGraph;
    edgeListGraph.insertVertex('A');
    edgeListGraph.insertVertex('B');
    edgeListGraph.insertEdge('A', 'B', 'X');
    edgeListGraph.print();
};