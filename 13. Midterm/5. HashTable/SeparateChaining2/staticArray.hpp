#include <iostream>
#include <cstdlib>

using namespace std;

class ArrayStatic {

    int* array;
    int count;

    public:

    ArrayStatic(){
        count = 0;
        array = new int[5];
    }


    int insert(int value, int index){

        if (count == 5) {
            throw logic_error("Array " + to_string(index) + " is full." + to_string(value));
        }

        for (int i = 0; i < 5; i++){
            if (array[i] == value){
                throw logic_error("already added key " + value);
            }
        }

        array[count++] = value;
        return count;
    }

    int search(int value){

        for (int i = 0; i < 5; i++){
            if (array[i] == value){
                return count;
            }
        }

        return -1;
    }

    int remove(int value){

        int pos;
        for (int i = 0; i < 5; i++){
            if (array[i] == value){
                pos = i;
                break;
            }
        }

        for (int i = pos; i < 4; i++){
            array[i] = array[i + 1];
        }

        count--;
        return count;
    }

    void print(){

        for (int i = 0; i < count; i++){
            cout << array[i] << "\t";
        }
        
    }
};