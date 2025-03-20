#include "list.hpp"
#include <cstdlib>
#include <iostream>
using namespace std;

// WARNING! Do not modify this struct!
// Doing so will nullify your score for this activity.
struct node {
    int element;
    node* next;
};

/**
 * This implementation is of a Singly-Linked List.
 * Feel free to add helper methods. You might want the create_node helper method.
 */
class LinkedList : public List {
    node* head;
    node* tail;
    int index;

    node* create_node(int num) {
      node* n = new node();
      n->element = num;
      n->next = nullptr;
      return n;
    }

    public:
        LinkedList() {
            head = nullptr;
            tail = nullptr;
            head = tail;
            index = 0;
        }

        int add(int num) {
            node* n = create_node(num);
            if (!head){
                head = n;
                tail=n;
                
                
            } else {
                tail->next = n;
                tail = n;
            }
            
            index++;
            return index;
        }

        int get(int pos) {
            if (pos >= index) return -1;
          node* curr = head;
          for (int i = 0; i < pos; i++){
              curr = curr->next;
          }
          return curr->element;
        }

        int size() {
            return index;
        }

        void swap(int pos1, int pos2) {
            if (pos1 == pos2 || pos1 >= index || pos2 >= index) return;
            
            // node* prev1 = nullptr;
            // node* prev2 = nullptr;
            node* node1 = head;
            node* node2 = head;
            
            for (int i = 0; node1 && i < pos1; i++){
                // prev1 = node1;
                node1 = node1->next;
            }
            
            for (int i = 0; node2 && i < pos2; i++){
                // prev2 = node2;
                node2 = node2->next;
            }
            
           int temp = node2->element;
            node2->element = node1->element;
            node1->element = temp;
        }

        // WARNING! Do not modify this method below!
        // Doing so will nullify your score for this activity.
        void print() {
            node* currnode = head;
            if (head == NULL && tail == NULL) {
                cout << "(empty)";
                return;
            }
            while (true) {
                cout << currnode->element;
                if (currnode == tail) {
                    cout << endl;
                    return;
                }
                cout << " -> ";
                currnode = currnode->next;
            }
        }
};