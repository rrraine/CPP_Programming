#include<iostream>
#include "node.hpp"
#include "RedBlack.hpp"
using namespace std;


class RedBlackTree : public RedBlack{


    node* root;
    node* null;
    int size;

    node* createNode(int n, node* parent){
        return new node{0, true, parent, null, null};
    }

    // insert

    void nodeTransplant(node* v, node* u){
        
    }

    // search

    // deletion
    public:

    RedBlackTree(){
        null = new node{0, false, nullptr, nullptr, nullptr};
        size = 0;
        root = null;
    }
    void insert(int num){

    }

    void remove (int num){

        
    }

    bool findNode(int num){

    }

};
