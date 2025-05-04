//#include <bits/stdc++.h>
#include <iostream>
#include <cstdlib>
using namespace std;


int* arr;
int n;
void print();
void sort_pivot(int left, int right);

int main(void){
    cout << "Enter number of elements: ";
    cin >> n;
    arr = (int*) malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        cout << "Enter element " << i+1 << ": ";
        cin >> arr[i];
    }

    sort_pivot(0, n-1);
    cout << "Finish: ";
    print();

    return 0;
};

void sort_pivot(int start, int end){
    cout << "Sorting: " << start << " to " << end << endl;

    // 1. choose pivot
    int pivot = start++;

    // 2. from after pivot, go through the elements and print every swap
// 4271 -> 4217 -> 1247
    for(int i  = start; i <= end; i++){
        if (arr[pivot] > arr[i]){
            cout << "Swapping: " << arr[start] << " and " << arr[i] << endl;
            swap(arr[start], arr[i]);
            if (start++ != i){
                print();
            }
        }
    }

    // 3. swap pivot with the last element smaller than it
    if (pivot < start - 1){ // pivot is less than the current start
        swap(arr[pivot], arr[start - 1]);
        print();
    }

    // 4. recursive call to left partition, if any
    if (start - 2 > pivot){
        sort_pivot(pivot, start-2);
    }

    // recursive call to right partition

    if (end > start){
        sort_pivot(start, end);
    }
}

void print() {
   cout<< "[";
   for (int i = 0; i < n; i++){
    cout << arr[i] << " ";
    if (i < n-1){
        cout << ", ";
    }
   }
   cout << "]" << endl;
}