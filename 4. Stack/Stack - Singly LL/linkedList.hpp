#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP

#include <cstdlib>
#include <iostream>
#include "list.hpp"
#include "node.hpp"
using namespace std;

class LinkedList : public List {
	node* head;
    node* tail;
	int size;

	public:
	
	LinkedList(){
	    head = nullptr;
        tail = nullptr;
	    size = 0;
	}
    // TODO if necessary
	int removeHead() {
        if (!head) return 0;

        node* temp = head;
        int top = temp->elem;  
        head->next = head;
        delete temp;
        size--;
        return top; 
	}

    // TODO if necessary
	void addTail(int num) {

    }

    // TODO if necessary
    void addHead(int num) {
        node* newNode = new node();
        newNode->elem = num;
        newNode->next = head;
        head = newNode;
        size++;
    }

    // TODO if necessary
    
    void add(int num) {
        node* newNode = new node();
        newNode->elem = num;

        if (!head){
            head = new node();
            tail = new node();
            newNode->next = nullptr;
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
        size++;
    }

    // TODO add more methods as necessary

    int _size() {
    	return size;
	}

    int get(int pos) {
        if (pos < 0 || pos >= size) {
            return -1;
        }

        if (pos == 1) {
            return head->elem;
        }

        node* curr = head;

        for (int i = 1; i < pos; i++){
            curr = curr->next;
        }

        return curr->elem;
        
    	//return 0;
    }

    int remove(int num) {
        return 0;
	}

    void print() {
    	node* curr = head;
    	if (size == 0) {
    		cout << "Empty" << endl;
		}
		else {
	    	do {
	    		cout << curr->elem;
	    		if (curr->next) {
	    			cout << " -> ";
				} else {
					cout << endl;
				}
	    		curr = curr->next;
			} while (curr);
		}
    }
};

#endif