// #ifndef RED_BLACK_REDBLACK_H
// #define RED_BLACK_REDBLACK_H

#include <iostream>
#include "node.hpp"
using namespace std;

class RedBlack {
    /// null pointer will improve deletenode algorithm significantly

    node* root, *null;
    int size;
   
    // helper functions
    node* createnode(int num, node* parent);
    void insertHelper(int num, node* node);
    void rotateLeft(node* node);
    void rotateRight(node* node);
    void insertFix(node* node);
    void nodeTransplant(node* v, node* u);
    node* findnodeHelper(node* node, int num);
    node* findnode(int num);
public:
    RedBlack();
    void insert(int num);
    void deletenode(int num);
    bool search(int num);
    void print();
    void print(const std::string& pre, char loc, node* node);
};


// #endif //RED_BLACK_REDBLACK_H