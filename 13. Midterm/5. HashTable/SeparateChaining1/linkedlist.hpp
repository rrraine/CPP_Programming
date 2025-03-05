#include <iostream>
#include "node.hpp"
using namespace std;

class LinkedList{

    int count;
    node* head;
    node* tail;

    void addBetween(node* curr, node* prev, string key){
        node* n = new node();
        n->elem = key;
        n->next = curr;
        n->prev = prev;
        curr->prev = n;
        prev->next = n;
        count++;
    }

    void removeBetween(node* curr){
        if (curr == head || curr == tail){
            return;
        }


        curr->prev->next = curr->next;
        curr->next->prev = curr->prev;
        delete curr;
        count--;
    }

    public:

    LinkedList(){
        head = new node();
        tail = new node();
        head->next = tail;
        tail->prev = head;
        count = 0;
    }

    int insert(string key){

        if (head->next == tail){
            addBetween(tail, head, key);
            return count;
        }
        node* curr = head->next;

        while(curr != tail){
            if (curr->elem == key){
                throw logic_error("Already added key " + key);
            }
            curr = curr->next;
        }

        addBetween(tail, tail->prev, key);
        return count;

    }

    int search(string key){

        node* curr = head->next;
        while(curr != tail){

            if (curr->elem == key){
                return count;
            }
            curr = curr->next;

        }
        return -1;
    }

    int remove(string key){

        node* curr = head->next;
        while (curr != tail){
            if (curr->elem == key){
                removeBetween(curr);
                return count;
            }
            curr = curr->next;
        }

        return -1;

    }

    void print(){

        node* curr = head->next;
        while (curr != tail){
            cout << curr->elem << " ";
            curr = curr->next;
        }
        cout << endl;

    }
};