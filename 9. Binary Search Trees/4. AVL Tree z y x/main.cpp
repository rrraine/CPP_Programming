#include <iostream>
#include <string>
#include "avltree.hpp"
using namespace std;

int main() {
    AVLTree* avl = new AVLTree();
    char op;
    int num;
    do {
        cout << "Op: ";
        cin >> op;
        switch (op) {
            case 'i':
                cin >> num;
                avl->insert(num);
                break;
            case 'r':
                cin >> num;
                avl->remove(num);
                break;
            case  'R':
                cin >> num;
                avl->zigleft(num);
                break;   
            case 'L':
                cin >> num;
                avl->zigright(num);
                break;    
            case 'p':
                avl->print();
                break;
            case 'x':
                cout << "Exiting" << endl;
                break;
            default:
                cout << "Invalid operation" << endl;
                break;
        }
    } while (op != 'x');
    return 0;
}