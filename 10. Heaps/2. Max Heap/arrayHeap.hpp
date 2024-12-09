#include <iostream>
#include <cstdlib>
#include <cmath>
#include "maxHeap.hpp"
using namespace std;

class ArrayMaxHeap : public MaxHeap {
    int* array;
    int size;
    int capacity = 5;

	int left(int n) {
        // TODO return the index of the left child of n
        return (2 * n) + 1;
	}

	int right(int n) {
        // TODO return the index of the right child of n
        return (2 * n) + 2;
	}
	
	// helper function
	int parent (int n){
	    return (n-1)/2;
	   
	}
	
	void Increase_resize(){
	    capacity = ceil (capacity * 1.5);
        array = (int*)realloc(array, sizeof(int) * capacity);
	}
	
	void Decrease_resize(){
	   int new_size = max(5, (int)ceil(capacity*0.8));
       capacity = new_size;
       array = (int*)realloc(array, sizeof(int) * capacity);
	}
	
	void swap(int& a, int& b){
	    int temp = a;
	    a = b;
	    b = temp;
	}

    public:
    ArrayMaxHeap() {
    	// TODO perform memory allocation for array with capacity 5
    	array = (int*)malloc(sizeof(int) * capacity);
    	size = 0;
	}

    // TODO insert the num into the heap
	void insert(int num) {

        if (size == capacity){
            Increase_resize();
        }
        int current = size;
        array[size++] = num;

        while (current > 0 && array[current] > array[parent(current)]){
            swap(array[current], array[parent(current)]);
            current = parent(current);
        }

	}

    // TODO remove the minimum value, -1 if empty
	int removeMax() {
		if(size == 0){
		    return -1;
		}

        int max = array[0];
        array[0] = array[size - 1];
        size--;

        int current = 0;

        while (true){
            int leftChild, rightChild, largest;

            leftChild = left(current);
            rightChild = right(current);
            largest = current;

            if (leftChild < size && array[leftChild] > array[largest]){
                largest = leftChild;
            }

            if (rightChild < size && array[rightChild] > array[largest]){
                largest = rightChild;
            }

            if (largest == current){
                break;
            }

            swap(array[current], array[largest]);
            current = largest;
        }

        if (size <= (capacity * 0.75)){
            Decrease_resize();
        }

        return max;
	}

    // DO NOT modify the code below
	void print() {
		if (size == 0) {
			cout << "EMPTY" << endl;
			return;
		}
			cout << "Size: " << size << "/" << capacity << endl;
			cout << "TREE: " << endl;
			print_tree("", 0, false);
			
			cout << "ARRAY: ";
    		for (int i = 0; i < size; i++) {
    			cout << array[i] << " ";
    		}
    		cout << endl;
		
		
	}

	void print_tree(string prefix, int n, bool isLeft) {
		cout << prefix;
        cout << (isLeft ? "+--L: " : "+--R: " );
        cout << array[n] << endl;
		if (left(n) < size) {
			print_tree(prefix + "|   ", left(n), true);
		}
		if (right(n) < size) {
			print_tree(prefix + "|   ", right(n), false);
		}
	}
};