#include "RedBlack.hpp"
#include "node.hpp"
#include <iostream>
using namespace std;

RedBlack::RedBlack() {
    root = nullptr;
    null = new node;
    null->isRed = false;
    null->elem = 0;
    null->parent = nullptr;
    null->left = nullptr;
    null->right = nullptr;

    size = 0;
    
}


// helperMethods
node *RedBlack::createnode(int num, node* parent){
    // node* n = new node();
    // n->elem = num;
    // n->isRed = true;
    // n->parent = parent;
    // n->left = nullptr;
    // n->right = nullptr;
    // return n;

    return new node{num, true, parent, null, null};
}


void RedBlack::rotateLeft(node* n){
    node* right = n->right;
    node* rightLeft = right->left;
    nodeTransplant(n, right);
    n->parent = right;
    right->left = n;
    n->left = rightLeft;
    if (rightLeft != null){
        rightLeft->parent = n;
    }

}
void RedBlack::rotateRight(node* n){
    node* left = n->left;
    node* leftRight = left->right;
    nodeTransplant(n, left);
    n->parent = left;
    left->right = n;
    n->right = leftRight;
    if (leftRight != null){
        leftRight->parent = n;
    }
}



void RedBlack::nodeTransplant(node* v, node* u){
    if (v == root){
        root= u;
    } else if (v->parent->left == v){
        v->parent->left = u;
    } else {
        v->parent->right = u;
    }
    u->parent = v->parent;

}

void RedBlack::insertFix(node* n){
    for (node* curr = n; curr->parent && curr->parent->isRed;){

        // get the gp of the node and define uncle
        node* gp = curr->parent->parent, *uncle;

        // Case1: If parent of node is gp's left child
        if (gp && gp->left == curr->parent){
            uncle = gp->right;

            // Case1.1: If uncle is red, recolor and move up the tree
            if (uncle->isRed){
                uncle->isRed = false;
                curr->parent->isRed = false;
                gp->isRed = true;
                curr = gp;
                continue;
            }

            // Case1.2: If uncle is black, rotate and recolor
            //Case1.2.1: If node is right child of parent, rotate left
            gp->isRed = true;
            if (curr->parent->right == curr){
                curr->parent->isRed = true;
                rotateLeft(curr->parent);
            } else {
                curr->parent->isRed = false;
            }

            //Case1.2.2: If node is left child of parent, rotate right
            rotateRight(gp);            

        }
        // Case2: If parent of node is gp's right child
        else if (gp && gp->right == n->parent){
            uncle = gp->left;
            
            if (uncle->isRed){
                uncle->isRed = false;
                curr->parent->isRed = false;
                gp->isRed = true;
                curr = gp;
                continue;
            }

            gp->isRed = true;

            if (curr->parent->left == curr){
                curr->parent->isRed = true;
                rotateRight(curr->parent);
            } else {
                curr->parent->isRed = false;
            }

            rotateLeft(gp);

        } else {
            break;
        }
    }
    root->isRed = false;
}

void RedBlack::insertHelper(int num, node* n){
    if (num < n->elem){
        if (n->left != null){
            insertHelper(num, n->left);
        } else {
            n->left = createnode(num, n);
            insertFix(n->left);
        }
    } else {
        if (n->right != null){
            insertHelper(num, n->right);
        } else {
            n->right = createnode(num, n);
            insertFix(n->right);
        }
    }
}



node* RedBlack::findnodeHelper(node* node, int num){
    return null;
}

node* RedBlack::findnode(int num){
    return null;
}




//  primary methods
void RedBlack::insert(int num){
    if (root == null){
        root = createnode(num, null);
    } else {
        insertHelper(num, root);
    }
    size++;
}
void RedBlack::deletenode(int num){

}
bool RedBlack::search(int num){
    return false;
}



void RedBlack::print() {
    cout << "Size: " << size << '\n';
    print("", 'Q', root);
}

void RedBlack::print(const std::string& pre, char loc, node *node) {
    if(node != null){
        cout << pre << "|--" << loc << ": " << node->elem << (node->isRed ? "(R)" : "(B)") << '\n';
        print(pre + "    ", 'L', node->left);
        print(pre + "    ", 'R', node->right);
    }
}


using namespace std;
int main() {
    auto* tree = new RedBlack();
    char op;
    int num;
    do{
        cout << "Op: ";
        cin >> op;
        try{
            switch (op) {
                case 'i':
                    cin >> num;
                    tree->insert(num);
                    break;
                case 'p':
                    tree->print();
                    break;
                case 's':
                    cin >> num;
                    cout << num << (tree->search(num) ? "" : " doesn't") << " exists\n";
                    break;
                case 'd':
                    cin >> num;
                    break;
                case 'x':
                    cout << "Existing...";
            }
        }catch (const std::exception& e){
            cout << e.what();
        }
    }while(op != 'x');
    return 0;
}