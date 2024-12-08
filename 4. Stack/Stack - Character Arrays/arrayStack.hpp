#include <iostream>
#include "arraylist.hpp"
#include "stack.hpp"
using namespace std;

class ArrayStack : public Stack {
    ArrayList* list;

    public:

    ArrayStack(){
        list = new ArrayList();
    }

    // todo

    void push(char c){
        list->add(c);
    }

    char top(){
        return list->get(1);
    }
    char pop(){
        return list->removeLast();
    }

    int size(){
        return list->_size();
    }

    bool isEmpty(){
        return size() == 0;
    }

    void print(){
        list->print();
    }

};