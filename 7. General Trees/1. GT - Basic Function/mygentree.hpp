#include <stdexcept>
#include <iostream>
#include <cstdlib>
#include "gentree.hpp"
using namespace std;

class MyGenTree : public GenTree {
	node* root;
	// node* children;
	int size;
    // int i;
    
    node* createNode(int elem){
        node* newNode = new node();
        newNode->num_child = 0;
        newNode->elem = elem;
        newNode->parent = nullptr;
        newNode->children = (node**)malloc(0);
        size++;
        return newNode;
    }
    
    void resizeChildrenNumber(node* n){
       n->children = (node**) realloc (n->children, sizeof(node*) * n->num_child);
    }
    
	public:
	
	MyGenTree(){
        size = 0;
        root = nullptr;
	    
	}
	
	int getSize() {
	    return size;
	}

	node* getRoot() {
	    return root;
	}
	
	node* addRoot(int e) {
		if (root){
            throw logic_error ("Already has root");
        }

        node* n = createNode(e);
        root = n;
        return n;    
	
	}

	node* addChild(node* p, int e) {
        node* n = createNode(e);
        p->num_child++;
        p->children[p->num_child - 1] = n;
        n->parent = p;
        return n;
	}


	void remove(node* n) {
		// TODO implementation [+35 pts]
        if (n->num_child > 2){
            throw logic_error("Node has children");
        }

        if (n->parent){
            for (int i = 0; i < n->parent->num_child; i++){
                if (n->parent->children[i] == n){

                    for (int j = i+1; j < n->parent->num_child; j++){
                        n->parent->children[j-1] = n->parent->children[j];
                    }
                    n->parent->num_child--;
                    resizeChildrenNumber(n->parent);
                    break;
                }
            }
        } else {
            root = nullptr;
        }

        delete n;
        size--;
	}
	
    void preOrderTraversal(){
        
    }

    void postOrderTraversal(){

    }

    void inOrderTraversal(){

    }

    // DO NOT MODIFY this line onwards.
	void print() {
		cout << "Size: " << size << endl;
		if (!root) {
			cout << "EMPTY" << endl;
			return;
		}
		node* curr = root;
		print_node("", root);
        cout << "Status: " << check_parent(root, NULL) << endl;
	}

	void print_node(string prefix, node* n) {
		cout << prefix;
        cout << "+-->: ";
        cout << n->elem << endl;
		for (int i = 0; i < n->num_child; i++) {
			print_node(prefix + "|   ", n->children[i]);
		}
	}

    bool check_parent(node* curr, node* par) {
        if (!curr) {
            return true;
        }
        if (curr->parent != par) {
            return false;
        }
        bool res = true;
		for (int i = 0; i < curr->num_child; i++) {
			res &= check_parent(curr->children[i], curr);
		}
        return res;
    }
};