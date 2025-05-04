#include "node.hpp"
#include <iostream>
#include <cstdlib>
using namespace std;


class BSTree {
    node* root;
    int size;

    node* create_node(int num, node* parent){
        node* n = (node*)malloc(sizeof(node));
        n->element = num;
        n->parent = parent;
        n->left = NULL;
        n->right = NULL;
        return n;
    }

    // helper

    bool searchHelper(int num, node* curr){ // restructure
        node* searchedNode = search_node(root, num);

        while(searchedNode->parent){
            restructure(searchedNode);
        }

        return root->element == num; // check if root is the searched node

    }

    node* search_node(node* curr, int num){ // find the node itself/ appropriate parent
        if (curr->element == num) return curr;

        if (num < curr->element){
            if (curr->left != NULL){
                return search_node(curr->left, num);
            }
            return curr;
        } 

        if (curr->right != NULL){
            return search_node(curr->right, num);
        }

        return curr;
    }

    public:

    BSTree(){
        root = NULL;
        size = 0;
    }

    bool search(int num){
        return searchHelper(num, root);
    }

    bool insert(int num){
        if (root == NULL){
            root = create_node(num, NULL);
            size++;
            return true;
        } else {
            node* parent = search_node(root, num);

            if(parent-> element != num){
                node* newN = create_node(num, parent);

                if (parent->element < num){
                    parent->right = newN;
                } else {
                    parent->left = newN;
                }

                while (newN->parent){
                    restructure(newN);
                }

                size++;
                return true;
            }
        }

        return false;
        
    }

    bool remove(int num){
        if (isEmpty()) return false;

        node* rem_node = search_node(root, num);

        if (rem_node->element != num) return false;

        // 1. find the num of child

        int children = 0;

        // 0 - no child
        // -1 - left child
        // 1 - right child
        // 2 - both child

        if(rem_node->right) children = 1;

        if (rem_node->left){
            if (children == 1){
                children = 2;
            } else {
                children = -1;
            }
        }


        // t1: no child
        if (children == 0){
            node* parent = rem_node->parent;
            if (!parent){
                root = NULL;
            } else {
                if (rem_node == parent->left){
                    parent->left = NULL;
                } else {
                    parent->right = NULL;
                }
            }


            // add restructure here
            if (parent){
                while(parent->parent){
                    restructure(parent);
                }
            }

            free(rem_node);
            size--;
        } else if (children == 1 || children == -1){
            node* parent = rem_node->parent;
            node* child;

            if (children == 1){
                child = rem_node->right;
            } else {
                child = rem_node->left;  
            }

            child->parent = parent;

            if (!parent) {
                root = child;
            } else {
                if (parent->left == rem_node) {
                    parent->left = child;
                } else {
                    parent->right = child;
                }
            }

            // add restructure here
            if (parent){
                while(parent->parent){
                    restructure(parent);
                }
            }

            free(rem_node);
            size--;

        } else { // two children
            node* right_st = rem_node->right;
            while (right_st->left != NULL) {
                right_st = right_st->left;
            }

            int temp = right_st->element;
            remove(temp);
            rem_node->element = temp;
        }
        return true;
        

    }

    // other functions
    node* transplant(node* u, node* v){

        if (u == root){
            root = v;
        } else if (u->parent->left == u){
            u->parent->left = v;
        } else {
            u->parent->right = v;
        }

        if (v){
            v->parent = u->parent;
        }
    }

    void zigleft(node* curr){

        node* left = curr->left;
        node* parent = curr->parent;
        transplant(curr, left);
        curr->left = parent;
        parent->parent = curr;
        parent->right = left;
       

        if (left){
            left->parent = parent;
        }

    }

    void zigright(node* curr){
        node* right = curr;
        node* parent = curr->parent;
        transplant(curr, right);
        curr->right = parent;
        parent->parent = curr;
        parent->left = right;

        if (right){
            right->parent = parent;
        }
    }

    void restructure(node* child){

        // 1. find parent

        node* par = child->parent;

        bool ptocRight = false;
        if (par->right == child) ptocRight = true;


        // 2. find grandparent, if any
        node* gpar = par->parent;

        if(!gpar){ // p is root
            // check if zigleft or zigright
            if (ptocRight){
                cout << "ZIGLEFT" << endl;
                zigleft(child);
            } else {
                cout << "ZIGRIGHT" << endl;
                zigright(child);
            }
        }

        bool gtopRight = false;
        if (gpar->right == par) gtopRight = true;


        if (gtopRight && ptocRight){
            cout<< "ZIGZIGLEFT" << endl;
            zigleft(par);
            zigleft(child);
        } else if (gtopRight && !ptocRight){
            cout << "ZIGZAGLEFT" << endl;
            zigright(child);
            zigleft(child);
        } else if (!gtopRight && !ptocRight){
            cout << "ZIGZIGRIGHT" << endl;
            zigright(par);
            zigright(child);
        } else {
            cout <<"ZIGZAGRIGHT" << endl;
            zigleft(child);
            zigright(child);
        }
    }







    // WARNING. Do not modify the methods below.
    // Doing so will nullify your score for this activity.
    void print() {
        if (isEmpty()) {
            cout << "EMPTY" << endl;
            return;
        }
        cout << "PRE-ORDER: ";
        print_preorder(root);
        cout << endl << "IN-ORDER: ";
        print_inorder(root);
        cout << endl << "POST-ORDER: ";
        print_postorder(root);
        cout << endl << "STATUS: " << check_health(root, NULL) << endl;
    }

    bool isEmpty() {
        return size == 0;
    }

    void print_preorder(node* curr) {
        cout << curr->element << " ";
        if (curr->left != NULL) {
            print_preorder(curr->left);
        }
        if (curr->right != NULL) {
            print_preorder(curr->right);
        }
    }

    void print_inorder(node* curr) {
        if (curr->left != NULL) {
            print_inorder(curr->left);
        }
        cout << curr->element << " ";
        if (curr->right != NULL) {
            print_inorder(curr->right);
        }
    }

    void print_postorder(node* curr) {
        if (curr->left != NULL) {
            print_postorder(curr->left);
        }
        if (curr->right != NULL) {
            print_postorder(curr->right);
        }
        cout << curr->element << " ";
    }

    bool check_health(node* curr, node* parent) {
        bool health = curr->parent == parent;
        if (curr->left != NULL) {
            health &= check_health(curr->left, curr);
        }
        if (curr->right != NULL) {
            health &= check_health(curr->right, curr);
        }
        return health;
    }
};