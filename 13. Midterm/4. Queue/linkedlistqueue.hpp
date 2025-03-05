#include "queue.hpp"
#include "node.hpp"
#include <iostream>
#include <stdexcept>
using namespace std;

class LinkedListQueue : public Queue {
	node* head;
	node* tail;
	int _size;

	public:
		LinkedListQueue() {
            head = new node();
            tail = head;
            _size = 0;
		}

        // 10
		void enqueue(int num) {
            if(!head){
                head->elem = num;
                tail = head;
            }
            
            
            // tail->next = n;
            node* n = new node();
            n->elem = num;
            n->next = nullptr;
            tail->next = n;
            tail = n;
            _size++;
            
     
		}

        // 13
		int dequeue() {
            if (isEmpty()){
                throw logic_error ("Cannot remove from empty queue");
            }
            
            
            node* temp = head->next;
            int t = temp->elem;
            head->next = temp->next;
            if (head->next == nullptr){
                tail = head;
            }
            
            delete temp;
            _size--;
            
            return t;
		}

        // 3
		int first() {
            if (isEmpty()){
                throw logic_error ("Cannot retrieve from empty queue");
            }
            
            return head->next->elem;
		}

        // 0
		int size() {
            return _size;
		}
        
        // 1
		bool isEmpty() {    
            return _size == 0;
		}
};