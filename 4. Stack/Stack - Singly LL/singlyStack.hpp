//TODO implement the class SinglyStack here
// by inheriting the Stack class

#include <iostream>
#include "linkedList.hpp"
#include "stack.hpp"
using namespace std;

class SinglyStack : public Stack{

    LinkedList* stack;
    
    public:
    
    SinglyStack() {
        stack = new LinkedList();
    }
    
    void push(int e){
        stack->addHead(e);
    }
    
    int top(){
        if (stack->get(1) == -1) return 0;

        return stack->get(1);
    }
    
    int size() {
        return stack->_size();
    }
    
    int pop(){
        return stack->removeHead();
    
    }
    
    bool isEmpty(){
        return size() == 0;
    }
    
    void print(){
        stack->print();
        return;
    }
    
};