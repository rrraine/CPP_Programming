#include "stack.hpp"
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <stdexcept>
using namespace std;

class ArrayStack : public Stack {
	int* array;
	int _size;
	int capacity;

    // T(n) =  8
    void sizeUp(){
        capacity = ceil(1.5 * capacity);
        array = (int*)realloc(array, capacity * sizeof(int));
    }
    
    //T(n) = 8
    void sizeDown(){
        capacity = ceil(0.75 * capacity);
        array = (int*)realloc(array, capacity * sizeof(int));
    }
	public:
		ArrayStack() {
		    capacity = 5;
		    _size = 0;
		    array = (int*)malloc(capacity * sizeof(int));

		}
        
        // T(n) = 11
		void push(int num) {
		    if (_size == capacity){
		        sizeUp();
		    }
            array[_size++] = num;
		}

        // T(n) = 1
		int pop() {
		    if (isEmpty()){
		        throw logic_error ("Cannot remove from empty stack");
		    }
            int t = top();
            _size--;
            if (_size == floor(_size * 2.0/3)){
                sizeDown();
            }
            return t;
		}

        // T(n) = 2
		int top() {
		    if (isEmpty()){
		        throw logic_error ("Cannot retrieve from empty stack");
		    }
            return array[_size-1];
		}

        //T(n) = 1
		int size() {
            return _size;
		}

        // T(n) = 1
		bool isEmpty() {
            return _size == 0;
		}
};