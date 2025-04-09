#include "node.hpp"
#include "tree.hpp"
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class AVLTree : public tree {
    private:
        node* root;
        int size;
    
        node* createNode(int num, node* parent = nullptr) {
            node* newNode = new node();
            newNode->element = num;
            newNode->parent = parent;
            newNode->left = nullptr;
            newNode->right = nullptr;
            return newNode;
        }
    
        void updateParent(node* child, node* parent) {
            if (child != nullptr) {
                child->parent = parent;
            }
        }
    
        node* searchNode(node* curr, int num) {
            if (curr == nullptr || curr->element == num) {
                return curr;
            }
            if (num < curr->element) {
                return curr->left ? searchNode(curr->left, num) : curr;
            }
            return curr->right ? searchNode(curr->right, num) : curr;
        }
    
        node* findMin(node* n) {
            while (n && n->left) {
                n = n->left;
            }
            return n;
        }
    
        int getBalanceFactor(node* n) {
            if (n == nullptr) return 0;
            int leftHeight = n->left ? n->left->height() : 0;
            int rightHeight = n->right ? n->right->height() : 0;
            return leftHeight - rightHeight;
        }
    
        void restructure(node* grandparent) {
            if (grandparent == nullptr) return;
    
            // Determine parent (the taller child of grandparent)
            node* parent = nullptr;
            int leftHeight = grandparent->left ? grandparent->left->height() : 0;
            int rightHeight = grandparent->right ? grandparent->right->height() : 0;
            
            if (leftHeight > rightHeight) {
                parent = grandparent->left;
            } else {
                parent = grandparent->right;
            }
    
            if (parent == nullptr) return;
    
            // Determine child (the taller child of parent)
            node* child = nullptr;
            int parentLeftHeight = parent->left ? parent->left->height() : 0;
            int parentRightHeight = parent->right ? parent->right->height() : 0;
            
            if (parentLeftHeight > parentRightHeight) {
                child = parent->left;
            } else if (parentRightHeight > parentLeftHeight) {
                child = parent->right;
            } else {
                // If heights are equal, choose the side that will require fewer rotations
                if (parent == grandparent->left) {
                    child = parent->left;  // Will result in single rotation
                } else {
                    child = parent->right; // Will result in single rotation
                }
            }
    
            // Perform the appropriate rotation(s)
            if (parent == grandparent->left) {
                if (child == parent->left) {
                    // Left-Left case (single right rotation)
                    cout << "ZIGRIGHT" << endl;
                    zigright(grandparent);
                } else {
                    // Left-Right case (double rotation)
                    cout << "ZIGZAGLEFT" << endl;
                    zigleft(parent);
                    zigright(grandparent);
                }
            } else {
                if (child == parent->right) {
                    // Right-Right case (single left rotation)
                    cout << "ZIGLEFT" << endl;
                    zigleft(grandparent);
                } else {
                    // Right-Left case (double rotation)
                    cout << "ZIGZAGRIGHT" << endl;
                    zigright(parent);
                    zigleft(grandparent);
                }
            }
        }
    
        void balance(node* start) {
            node* current = start;
            while (current != nullptr) {
                int balance = getBalanceFactor(current);
                if (abs(balance) > 1) {
                    restructure(current);
                    // After restructuring, we need to update heights up the tree
                    current = current->parent;
                    continue;
                }
                current = current->parent;
            }
        }
    
    public:
        AVLTree() : root(nullptr), size(0) {}
    
        void zigleft(node* n) override {
            if (n == nullptr || n->right == nullptr) return;
            
            node* rightChild = n->right;
            n->right = rightChild->left;
            updateParent(rightChild->left, n);
            
            rightChild->parent = n->parent;
            if (n->parent == nullptr) {
                root = rightChild;
            } else if (n == n->parent->left) {
                n->parent->left = rightChild;
            } else {
                n->parent->right = rightChild;
            }
            
            rightChild->left = n;
            n->parent = rightChild;
        }
    
        void zigright(node* n) override {
            if (n == nullptr || n->left == nullptr) return;
            
            node* leftChild = n->left;
            n->left = leftChild->right;
            updateParent(leftChild->right, n);
            
            leftChild->parent = n->parent;
            if (n->parent == nullptr) {
                root = leftChild;
            } else if (n == n->parent->right) {
                n->parent->right = leftChild;
            } else {
                n->parent->left = leftChild;
            }
            
            leftChild->right = n;
            n->parent = leftChild;
        }
    
        bool insert(int num) override {
            if (root == nullptr) {
                root = createNode(num);
                size++;
                return true;
            }
    
            node* parent = searchNode(root, num);
            if (parent->element == num) {
                return false; // Duplicate
            }
    
            node* newNode = createNode(num, parent);
            if (num < parent->element) {
                parent->left = newNode;
            } else {
                parent->right = newNode;
            }
            size++;
    
            // Balance the tree starting from the parent
            balance(parent);
            return true;
        }
    
        bool remove(int num) override {
            if (root == nullptr) return false;
    
            node* toRemove = searchNode(root, num);
            if (toRemove == nullptr || toRemove->element != num) {
                return false;
            }
    
            node* parent = toRemove->parent;
            
            // Case 1: No children
            if (toRemove->left == nullptr && toRemove->right == nullptr) {
                if (parent == nullptr) {
                    root = nullptr;
                } else if (parent->left == toRemove) {
                    parent->left = nullptr;
                } else {
                    parent->right = nullptr;
                }
                delete toRemove;
            }
            // Case 2: One child
            else if (toRemove->left == nullptr || toRemove->right == nullptr) {
                node* child = (toRemove->left != nullptr) ? toRemove->left : toRemove->right;
                if (parent == nullptr) {
                    root = child;
                } else if (parent->left == toRemove) {
                    parent->left = child;
                } else {
                    parent->right = child;
                }
                child->parent = parent;
                delete toRemove;
            }
            // Case 3: Two children
            else {
                node* successor = findMin(toRemove->right);
                toRemove->element = successor->element;
                // Recursively remove the successor (which will have 0 or 1 child)
                remove(successor->element);
                return true;
            }
    
            size--;
            // Balance the tree starting from the parent
            balance(parent);
            return true;
        }
    
        bool search(int num) {
            node* result = searchNode(root, num);
            return result != nullptr && result->element == num;
        }
    
        void print() override {
            printHelper(root, "", true);
        }
    
    private:
        void printHelper(node* n, string indent, bool last) {
            if (n != nullptr) {
                cout << indent;
                if (last) {
                    cout << "+--R: ";
                    indent += "    ";
                } else {
                    cout << "+--L: ";
                    indent += "|   ";
                }
                cout << n->element << endl;
                printHelper(n->left, indent, false);
                printHelper(n->right, indent, true);
            }
        }
    };