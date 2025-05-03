// RedBlackTree.hpp
#include <iostream>
#include <cassert>
#include "RedBlack.hpp"
#include "node.hpp"
using namespace std;

class RedBlackTree : public RedBlack {

private:

    node* root;
    node* tnull;
    int size;

    // Helper methods
    node* createNode(int num, node* parent) {
        // assert(tnull != nullptr); // Ensure tnull is initialized
        return new node{num, true, parent, tnull, tnull};
    }

    void rotateLeft(node* n) {
        if (n == nullptr || n->right == tnull) return;

        node* right = n->right;
        node* rightLeft = right->left;

        n->right = rightLeft;
        if (rightLeft != tnull){
            rightLeft->parent = n;
        }

        nodeTransplant(n, right);

        right->left = n;
        n->parent = right;
        n->right = rightLeft;
    
    
    }

    void rotateRight(node* n) {
        if (n == nullptr || n->left == tnull) return;
        
        node* left = n->left;
        node* leftRight = left->right;

        n->left = leftRight;
        if (leftRight != tnull){
            leftRight->parent = n;
        }

        nodeTransplant(n, left);

        left->right = n;
        n->parent = left;
        n->left = leftRight;

        if (leftRight != tnull) {
            leftRight->parent = n;
        }
        
    }

    void nodeTransplant(node* v, node* u) {
        if (v == root) {
            root = u;
        } else if (v->parent->left == v) {
            v->parent->left = u;
        } else {
            v->parent->right = u;
        }
        u->parent = v->parent;

        // if (u != tnull) {
        //     u->parent = v->parent;
        // }
        
    }

   void insertFix(node* n) {
    while (n->parent && n->parent->isRed) {
        node* gp = n->parent->parent;
        node* uncle;

        if (gp && gp->left == n->parent) {
            uncle = gp->right;

            if (uncle != tnull && uncle->isRed) {
                // Case 1: Uncle is red
                uncle->isRed = false;
                n->parent->isRed = false;
                gp->isRed = true;
                n = gp;  // Move up to grandparent
                continue;
            }

            if (n->parent->right == n) {
                // Case 2: n is right child, perform left rotation on parent
                n = n->parent;
                rotateLeft(n);
            }

            // Case 3: n is left child, perform right rotation on grandparent
            n->parent->isRed = false;
            gp->isRed = true;
            rotateRight(gp);
        } else {
            // Symmetric to the above case where parent is on the right
            uncle = gp->left;

            if (uncle != tnull && uncle->isRed) {
                // Case 1: Uncle is red
                uncle->isRed = false;
                n->parent->isRed = false;
                gp->isRed = true;
                n = gp;
                continue;
            }

            if (n->parent->left == n) {
                // Case 2: n is left child, perform right rotation on parent
                n = n->parent;
                rotateRight(n);
            }

            // Case 3: n is right child, perform left rotation on grandparent
            n->parent->isRed = false;
            gp->isRed = true;
            rotateLeft(gp);
        }
    }

    root->isRed = false;  // Root should always be black
}


    void insertHelper(int num, node* n) {
        if (num < n->elem) {
            if (n->left != tnull) {
                insertHelper(num, n->left);
            } else {
                n->left = createNode(num, n);
                insertFix(n->left);
            }
        } else {
            if (n->right != tnull) {
                insertHelper(num, n->right);
            } else {
                n->right = createNode(num, n);
                insertFix(n->right);
            }
        }
        size++;
    }


    node* findNodeHelper(node* n, int elem){
        if (!n ||n->elem == elem) {
            return n;
        } else if (elem < n->elem){
            return findNodeHelper(n->left, elem);
        } else {
            return findNodeHelper(n->right, elem);
        }

    }

    node* findNode(int num){
       return findNodeHelper(root, num);
    }

    // z - node to be deleted
    // y - node to be replaced with z
    // x - child of y that will replace y

    void deleteNodeHelper(node* n, int elem){
        node* z = tnull;
        node* x, *y;
        
        // Find the node to delete
        while (n != tnull) {
            if (n->elem == elem)
                z = n;
            if (elem < n->elem)
                n = n->left;
            else
                n = n->right;
        }
    
        if (z == tnull) {
            std::cout << "Key not found\n";
            return;
        }
    
        y = z;
        bool yOriginalColor = y->isRed;

        // case 1: one child
        if (z->left == tnull) {
            x = z->right;
            nodeTransplant(z, z->right);
        
        } else if (z->right == tnull) {
            x = z->left;
            nodeTransplant(z, z->left);
        
        } 
        // case 3: two children
        else {
            y = minimum(z->right);
            yOriginalColor = y->isRed;
            x = y->right;
            if (y->parent == z) {
                x->parent = y;
            } else {
                nodeTransplant(y, y->right);
                y->right = z->right;
                y->right->parent = y;
            }
    
            nodeTransplant(z, y);
            y->left = z->left;
            y->left->parent = y;
            y->isRed = z->isRed;
        }
    
        delete z;
        size--;
        if (!yOriginalColor) {
            deleteFix(x);
        }
        
    }
    

    void deleteFix(node* x){
        while (x != root && !x->isRed) {
            if (x == x->parent->left) {
                node* w = x->parent->right;
                if (w->isRed) {
                    w->isRed = false;
                    x->parent->isRed = true;
                    rotateLeft(x->parent);
                    w = x->parent->right;
                }
    
                if (!w->left->isRed && !w->right->isRed) {
                    w->isRed = true;
                    x = x->parent;
                } else {
                    if (!w->right->isRed) {
                        w->left->isRed = false;
                        w->isRed = true;
                        rotateRight(w);
                        w = x->parent->right;
                    }
    
                    w->isRed = x->parent->isRed;
                    x->parent->isRed = false;
                    w->right->isRed = false;
                    rotateLeft(x->parent);
                    x = root;
                }
            } else if (x == x->parent->right){
                // Same as above but mirror image
                node* w = x->parent->left;
                if (w->isRed) {
                    w->isRed = false;
                    x->parent->isRed = true;
                    rotateRight(x->parent);
                    w = x->parent->left;
                }
    
                if (!w->right->isRed && !w->left->isRed) {
                    w->isRed = true;
                    x = x->parent;
                } else {
                    if (!w->left->isRed) {
                        w->right->isRed = false;
                        w->isRed = true;
                        rotateLeft(w);
                        w = x->parent->left;
                    }
    
                    w->isRed = x->parent->isRed;
                    x->parent->isRed = false;
                    w->left->isRed = false;
                    rotateRight(x->parent);
                    x = root;
                }
            } else {
                break;
            }
        }
        x->isRed = false;
    }

    node* minimum(node* n){
        while (n->left != tnull){
            n = n->left;
        }
        return n;
    }

public:

    RedBlackTree() {
        size = 0;
        tnull = new node();
        tnull->isRed = false;
        tnull->elem = 0;
        tnull->parent = nullptr;
        tnull->left = nullptr;
        tnull->right = nullptr;
        root = tnull;
    }

    void insert(int elem) {
        cout << "Inserting: " << elem << endl;
        if (root == tnull) {
            root = createNode(elem, tnull);
            root->isRed = false;
        } else {
            insertHelper(elem, root);
        }
        cout << "Finished inserting: " << elem << endl;
    }

    void print() {
        printHelper(root, "", true);
    }

    bool search(int elem) {
        
        return findNode(elem) != nullptr && findNode(elem) != tnull;
    }

    void remove(int elem) {
        deleteNodeHelper(root, elem);
    }

    void printHelper(node* n, string indent, bool last) {
         if (n == nullptr || n == tnull) return;
         
        if (n != nullptr && n != tnull) {
            cout << indent;
            if (last) {
                cout << "+--R: ";
                indent += "    ";
            } else {
                cout << "+--L: ";
                indent += "|   ";
            }
            cout << n->elem << (n->isRed ? " (R)" : " (B)") << endl;
            printHelper(n->left, indent, false);
            printHelper(n->right, indent, true);
        }
    }
};


/*

1. insert
- if uncle is red, recolor
- if uncle is black, restructure

2. delete
- 

*/