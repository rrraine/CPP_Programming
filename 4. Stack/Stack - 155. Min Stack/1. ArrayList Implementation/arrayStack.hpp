#include <iostream>
#include "arrayList.hpp"
#include "stack.hpp"
using namespace std;

class MinStack : public Stack{
    ArrayList* mainStack; // Stack to store actual values
    ArrayList* minStack;  // Stack to store minimum values
public:
    MinStack() {
        mainStack = new ArrayList();
        minStack = new ArrayList();
    }

    void push(int val) {
        mainStack->add(val);
        if (minStack->isEmpty() || val <= minStack->top()) {
            minStack->add(val);
        }
    }

    int size(){
        return minStack->_size();
    }
    bool isEmpty(){
        return size() == 0;
    }

    int pop() {
        if (mainStack->isEmpty()) {
            cout << "Stack is empty!" << endl;
            return 0;
        }
        int poppedValue = mainStack->removeLast();
        if (poppedValue == minStack->top()) {
            minStack->removeLast();
        }

        return poppedValue;
    }

    int top() {
        if (mainStack->isEmpty()) {
            cout << "Stack is empty!" << endl;
            return -1;
        }
        return mainStack->top();
    }

    int getMin() {
        if (minStack->isEmpty()) {
            cout << "Stack is empty!" << endl;
            return -1;
        }
        return minStack->top();
    }

  

    void print() {
        cout << "Main Stack: ";
        mainStack->print();
        cout << "Min Stack: ";
        minStack->print();
    }
};
