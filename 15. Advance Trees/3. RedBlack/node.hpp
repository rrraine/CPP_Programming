// #ifndef RED_BLACK_node_H
// #define RED_BLACK_node_H
#pragma once
using namespace std;

struct node{
    int elem;
    bool isRed;
    node* parent, *right, *left;
};

// #endif //RED_BLACK_node_H