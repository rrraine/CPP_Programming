#include <iostream>
#include "arrayStack.hpp"
using namespace std;

int main() {
    Stack* minStack = new MinStack();
    int input;
    char op;
    do {
        cout << "Enter op: ";
        cin >> op;
        switch (op) {
            case 'a':
                
                cin >> input;
                minStack->push(input);
                break;
            case 'r':
                cout << "Removed " << minStack->pop() << endl;
                break;
            case 't':
                cout << "Last element: " << minStack->top() << endl;
                break;
            case 's':
                cout << "Size: " << minStack->size() << endl;
                break;
            case '?':
                cout << "Empty? " << (minStack->isEmpty() ? "Yes" : "No") << endl;
                break;
            case 'p':
                minStack->print();
                break;
            case 'x':
                cout << "Exiting" << endl;
                break;
            case 'm':
                cout << "Minimum element: " << minStack->getMin() << endl;
                break;
            default:
                cout << "Invalid operation!" << endl;
        }
    } while (op != 'x');
    return 0;
}