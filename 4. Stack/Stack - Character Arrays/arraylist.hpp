// TODO change this to handle char elements

#include <iostream>
#include <cstdlib>
#include <math.h>
#include "list.hpp"
using namespace std;

class ArrayList : public List {
    char* array;
    int size;
    int capacity = 5;

	void dynamic_add() {
		int new_size = ceil(capacity * 1.5);
        char* new_array = (char*) realloc(array, sizeof(char)*new_size);
        array = new_array;
        capacity = new_size;

	}

	void dynamic_deduce() {
		int new_size = ceil(capacity * 0.75);
        char* new_array = (char*) realloc (array, new_size* sizeof(char));
        array = new_array;
        capacity = new_size;
	}

    public:
    // constructor
    ArrayList() {
    	
        array = (char*) malloc(capacity * sizeof(char));
        size = 0;
    }

    void add(char c) {
        // TODO add num
        if (size == capacity){
            dynamic_add();
        }
        array[size++] = c;
    }

    int _size() {
        if (size < 0){
            size = 0;
        }
    	return size;
	}

    char removeLast() {
        // TODO remove and return last element
        /*
        char last = array[size-1];
        // size--;
        size = size - 1;
        return last;
        */
        if (size == 0){
            return ' ';
        }
        return array[--size];
	}


	int removeFirst() {
        // NOT NECESSARY
        return 0;
    }

    int remove(int num) {
        // NOT NECESSARY
        return 0;
    }

    char get(int pos) {
        if (size == 0){
            return ' ';
        }
        return array[pos-1];
    }
    
    char top(){
        return array[size-1];
    }

    void print() {
   		int i;
        for (i = 0; i < size; i++) {
            cout << array[i] << " ";
        }
        for (; i < capacity; i++) {
            cout << "? ";
		}
        cout << endl << size << "/" << capacity << endl;
    }
};