#include <bits/stdc++.h>
#include "list.hpp"
using namespace std;

// create node struct

struct node{
    int element;
    node* next;
};

class LinkedList : public List {

    node* create_node(int num){
        node* n= (node*)malloc(sizeof(node));
        n->element = num;
        return n;
    }
  
    public:

    node* head;
    node* tail;
    int index;

    LinkedList(){
        head = NULL;
        tail = NULL;
        index = 0;
    }

    void addTail(int num){
        node* n = create_node(num);
        if (tail!= NULL){
            tail->next = n;
        }

        tail = n;

        if (head == NULL){
            head = n;
        }

        index++;
    }

    int removeHead(){
        if (head == NULL){
            return;
        }

        int num = head->element;
        node* temp = head;
        head = head->next;
        free(temp);
        index--;

        return num;
    }

    // main

    int add(int num){
        addTail(num);
        return index;
    }
    
    int get(int pos){
        
        int count = 0;
        node* curr = head;

        while (curr != NULL){
            count++;
            if (count == pos){
                return curr->element;
            } else {
                curr = curr->next;
                
            }
        }
        return -1;
    }

    int size(){
        return index;
    }

// WARNING! Do not modify this method below!
    // Doing so will nullify your score for this activity.
    void print() {
        node* currnode = head;
        if (head == NULL && tail == NULL) {
            cout << "(empty)" << endl;
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