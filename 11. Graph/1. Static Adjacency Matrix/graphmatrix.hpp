#include <cstdlib>
#include <iostream>
#include "graph.hpp"
using namespace std;

class GraphMatrix : public Graph {
    int matrix[10][10];
    char s_vertices[10];
    int num_vert;
    int s_edges[100];
    int num_edge;

    public:
    GraphMatrix() {
        num_vert = 0;
        num_edge = 0;
    }

    int numVertices() {
        return num_vert;
    }

    char* vertices() {
        return s_vertices;
    }

    int numEdges() {
        return num_edge;
    }

    int* edges() {
        return s_edges;
    }

    bool insertVertex(char x)  {
        if (num_vert<= 10){
            s_vertices[num_vert++] = x;
            return true;
        }
        return false;
    }

    bool insertEdge(char u, char v, int x)  {
        
        int v1, v2;
        for (int i = 0; i < num_vert; i++){
            if (s_vertices[i] == u) v1 = i;
            if (s_vertices[i] == v) v2 = i;
        }

        for (int i = 0; i < num_vert; i++){
            for (int j = 0; j < num_vert; j++){
                if (matrix[i][j] == x){
                    cout << "Not null";
                    return false;
                }

                if (i == v1 && j == v2){
                    matrix[i][j] = x;
                    s_edges[num_edge++] = x; // na-add na here
                    return true;
                }
            }

        }

        return false;
    }

    int getEdge(char u, char v)  {
        int v1 = -1, v2 = -1;
        for (int i = 0; i < num_vert; i++){
            if (s_vertices[i] == u) v1 = i;
            if (s_vertices[i] == v) v2 = i;
        }

        if (matrix[v1][v2] == 0 || (v1 == -1 && v2 == -1)) return 0;

        return matrix[v1][v2];
    }

    char* endVertices(int e)  {
        char* endV;
        endV[0] = '-';
        endV[1] = '-';

        for (int i = 0; i < num_vert; i++){
            for (int j = 0; j < num_vert; j++){
                if (matrix[i][j] == e){
                    endV[0] = s_vertices[i];
                    endV[1] = s_vertices[j];
                    return endV;
                }
            }
        }

        return endV;
    }

    char opposite(char v, int e)  {
        for (int i = 0; i < num_vert; i++){
            for (int j = 0; j < num_vert; j++){
                if (matrix[i][j] == e){
                    if (s_vertices[i] == v) return s_vertices[j];
                    if (s_vertices[j] == v) return s_vertices[i];
                    
                }
            }
        }
        return '-';
    }

    int outDegree(char v)  { // row
        int v1, count = 0;
        for (int i = 0; i < num_vert; i++){
            if (s_vertices[i] == v) v1 = i;
        }
        for (int i = 0; i < num_vert; i++){
            for (int j = 0; j < num_vert; j++){
                if (i == v1 && matrix[i][j] != 0){
                    count++;
                }
            }
        }
        return count;
    }

    int inDegree(char v)  {
        return 0;
    }

    int* outgoingEdges(char v) {
        return NULL;
    }

    int* incomingEdges(char v) {
        return NULL;
    }

    int removeVertex(char v) {
        return 0;
    }

    bool removeEdge(int e)  {
        return false;
    }

    // DONT EDIT ---------------------

    void print() {
        cout << "\t";
        for (int i = 0; i < num_vert; i++) {
            cout << s_vertices[i] << "\t";
        }
        cout << endl;
        for (int i = 0; i < num_vert; i++) {
            cout << s_vertices[i] << "\t";
            for (int j = 0; j < num_vert; j++) {
                if (matrix[i][j] != 0) {
                    cout << matrix[i][j];
                }
                cout << "\t";
            }
            cout << endl;
        }
    }
};