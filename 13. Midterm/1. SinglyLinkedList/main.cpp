#include <iostream>
#include "linkedlist.hpp"
using namespace std;

int main() {
    List* list = new LinkedList();
    char ch;
    int num, pos, res;
    do {
        try {
            cout << "Op: ";
            cin >> ch;
            switch (ch) {
                case 'f':
                    cin >> num;
                    list->addFirst(num);
                    break;
                case 'l':
                    cin >> num;
                    list->addLast(num);
                    break;   
               
                case 's':
                    cout << "Size: " << list->size() << endl;
                    break;
                case '?':
                    cout << "Is Empty? " << list->isEmpty() << endl;
                    break;
                case 'r':
                    list->removeFirst();
                    cout << "Removed first element." << endl;
                    break;
                
                case '-':
                    list->removeLast();
                    cout << "Removed last element." << endl;
                    break;                
               
                case 'p':
                    list->print();
                    break;
                case 'x':
                    cout << "Exiting...";
                    break;
                default:
                    cout << "Invalid operation" << endl;
            }
        } catch (exception& e) {
            cout << e.what() << endl;
        }
    } while (ch != 'x');
    return 0;
}