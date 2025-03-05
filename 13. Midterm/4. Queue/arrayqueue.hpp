#include "queue.hpp"
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <stdexcept>
using namespace std;

class ArrayQueue : public Queue {
	int* array;
	int _size, capacity;
        // 8
     void sizeUp(){
        capacity = ceil(1.5 * capacity);
        array = (int*)realloc(array, capacity * sizeof(int));
    }
    //8    
    void sizeDown(){
        capacity = ceil(0.75 * capacity);
        array = (int*)realloc(array, capacity * sizeof(int));
    }
    
	public:
		ArrayQueue() {
            capacity = 5;
            _size = 0;
            array = (int*)malloc(capacity * sizeof(int));
		}
		
        //11
		void enqueue(int num) {
            if (_size == capacity){
                sizeUp();
            }
            
            array[_size++] = num;
		}

        // 5n^2 + 17
		int dequeue() {
            if (isEmpty()){
                throw logic_error("Cannot remove from empty queue");
            }
            
            //15
            int first_ = first();
            
            _size--;
            if (_size == floor(_size * 2.0/3)){
                sizeDown(); 
            }
            
            ///5n^2 + 2
            for (int i = 0; i < _size; i++){
                array[i] = array[i+1];
            }
            
            return first_;
		}
		
		// 1
		int first() {
            if (isEmpty()){
                throw logic_error("Cannot retrieve from empty queue");
            }
 
            return array[0];
            
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