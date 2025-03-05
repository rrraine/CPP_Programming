#include "stack.hpp"
#include "node.hpp"
#include <iostream>
#include <stdexcept>
using namespace std;

class LinkedListStack : public Stack {
	node* head;
	node* tail;
	int _size;

	public:
		LinkedListStack() {
            head = new node();
            tail = new node();
            _size = 0;
		}

        // T(n) = 11
		void push(int num) {
            node* n = new node();
            n->elem = num;
            n->next = head->next;
            head->next= n;
            _size++;
		}

        // T(N) = 10
		int pop() {
		    if (isEmpty()){
		        throw logic_error ("Cannot remove from empty stack");
		    }
		    
        
            node* curr = head->next;
            int t = curr->elem;
            
            head->next = curr->next;
            delete curr;
            _size--;
            return t;
		}

        // 1
		int top() {
		    if (isEmpty()){
		        throw logic_error ("Cannot retrieve from empty stack");
		    }
            return head->next->elem;
		}

        // 1
		int size() {
            return _size;
		}
        
        // 1
		bool isEmpty() {
            return _size == 0;
		}
};


   // if(!head){
            //     head->elem = num;
            // }
            
            // node* n = new node();
            // n->elem = num;
            // head->next = n;
            // tail = n;
            // _size++;

  //  int t = top();
		    
		  //  _size--;
		  //  node* curr = head;
		  //  for (int i = 0; i < _size; i++){
		  //      curr = curr->next;
		  //  }
		    
		    
		  //  node* temp = tail;
		  //  tail = curr;