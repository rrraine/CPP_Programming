#include <bits/stdc++.h>
#include "list.hpp"
#include "node.hpp"

using namespace std;

class LinkedList : public List{

    int _size;
    node* head;
    node* tail;
    
    public:

    LinkedList(){
        head = new node();
        tail = new node();
        head->next = tail;
     
        _size = 0;
    }


    void addFirst(int num) {
        node* n = new node();
        n->elem = num;
        if (head->next == tail){
            head->next = n;
            n->next = tail;
     
        } else {
            n->next = head->next;
            head->next = n;
        }
        _size++;
        
    }

    void addLast(int num) {
        node* temp = head->next;

        node* n = new node();
        n->elem = num;

        if (head->next == tail){
            addFirst(num);
        }

        while(temp->next != tail){
            temp = temp->next;
        }

        temp->next = n;
        n->next = tail;
        _size++;
    }

    void removeFirst() {
        if(head->next == tail){
            throw logic_error("List is empty");
        }

        node* temp = head->next;
        head->next = temp->next;
        delete temp;
        _size--;

        if (head->next == tail){
            tail = head;
        }
    }

    void removeLast() {
        if(head->next == tail){
            throw logic_error("List is empty");
        }

        node* temp = head->next;
        node* prev = head;

        while (temp->next != tail){
            prev = temp;
            temp = temp->next;
        }

        prev->next = tail;
        delete temp;
        _size--;

        if (head->next == tail){
            tail = head;
        }
    }


    void insert(int num){
        node* n = new node();
        n->elem = num;
        if (head->next == tail){
            head->next = n;
            n->next = tail;
        } else {
            node* temp = head;

            while (temp->next != tail){
                temp->next =temp;
            }

            temp->next = n;
            n->next = tail;
        }

        _size++;

    }

    int get(int pos){

        if (pos >= _size) throw out_of_range("Invalid position");
        
        node* temp = head->next;
        int i = 0;

        while (i < pos && temp != tail){
            temp = temp->next;
            i++;
        }

        return temp->elem; 

    }


    void print(){
        cout << "List: ";
        for (int i = 0; i < _size; i++){
            cout << get(i) << " ";
        }
        cout << endl;
    }

    int size(){
        return _size;
    }

    bool isEmpty(){
        return size() == 0;
    }

    


};