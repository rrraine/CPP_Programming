// TODO entire implementation
#include <bits/stdc++.h>
#include "list.hpp"
using namespace std;

class ArrayList : public List {
    
    int _size, capacity = 5;
    int* array;
    
    void sizeUp(){
        int newcapacity = ceil(capacity * 1.5);
        
        int* temp = (int*)realloc(array, newcapacity * sizeof(int));
        
        if (temp){
            array = temp;
            capacity = newcapacity;
        } else {
            cerr << "Failed" << endl;
        }
        
    }
    
    void sizeDown(){

        capacity = ceil(capacity * 0.75);
        
        if (capacity < 5) capacity = 5;

        array = (int*)realloc(array, capacity * sizeof(int));
    }
    
    public:
    
    ArrayList(){
        array = (int*)malloc(5 * sizeof(int));
        _size = 0;
    }
    
    void insert(int num){
        if (_size == capacity){
            sizeUp();
        }
        array[_size++] = num;
    }
    
    int get(int pos){
        
        if (pos > _size) {
            throw logic_error ("Invalid position");
        }
        return array[pos - 1];
    }
    
    int remove(int num){
        int index = -1, in = -1;
        for (int i = 0; i < _size; i++){
            if (array[i] == num) {
                index = i;
                in = i+1;
                break;
            }
        }
        
        if (index == -1) return 0;
        
        for (int i = index; i < _size - 1; i++){
            array[i] = array[i+1];
        }
        _size--;
        if (_size <= (capacity * 2/3.0)) sizeDown();
        return in;
    }
    
    void print(){
        for (int i = 0; i < capacity; i++){
            if (i < _size) {
                cout << array[i] << " ";
            } else {
                cout << "? ";
            }
            
            
        }
        cout << endl;
    }
    
    int size(){
        return _size;
    }
    
    bool isEmpty(){
        return size() == 0;
    }
    
    void addAt(int num, int pos){
        
        if (pos > _size + 1 || pos < 0) {
            throw logic_error ("Invalid position");
        }
        
        if (_size == capacity) sizeUp();
        
        for (int i = _size; i >= pos; i--){
            array[i] = array[i - 1];
        }
        
        array[pos - 1] = num;
        _size++;
     }
    
    int removeAt(int pos){
        if (pos > _size) {
            throw logic_error ("Invalid position");
        }
        
        int value = array[pos - 1];
        
        for (int i = pos - 1; i < _size - 1; i++){
            array[i] = array[i + 1];
        }
        
        _size--;
        
        if (_size <= (capacity * 2/3.0)) sizeDown();
        
        return value;
    }
    
    
};