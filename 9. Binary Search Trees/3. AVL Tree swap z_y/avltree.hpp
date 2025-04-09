#include "node.hpp"
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include "tree.hpp"
using namespace std;

class AVLTree : public tree {

    node* root;
    int size;

    node* create_node(int num, node* parent = nullptr){
        node* n = new node;
        n->element = num;
        n->parent = nullptr;
        n->left = nullptr;
        n->right = nullptr; 
    }

    void updateParent(node* child, node* parent){
        if(child){
            child->parent = parent;
        }
    }


    public:
    AVLTree(){
        root = nullptr;
        size = 0;
    }

    // minimal 
    // void zigleft(node*n){
    //     node* rightChild = n->right;
        
    //     if (n->parent == nullptr){
    //         root = rightChild;
    //     } else if (n->parent->left == n){
    //         n->parent->left = rightChild;
    //     } else {
    //         n->parent->right = rightChild;
    //     }   

    //     updateParent(rightChild, n->parent);
    //     n->parent = rightChild;
        
    // }

    // void zigright(node*n){

    // }

    bool insert(int num){

    }

    bool remove(int num){

    }

    void print(){

    }


    // minimal (swap two nodes)

    void zigleft(node*n){
       node* rightChild = n->right;

       updateParent(rightChild, n->parent);
        
    }

    void zigright(node*n){

        node* leftChild = n->left;

        updateParent(leftChild, n->parent);
    }


};