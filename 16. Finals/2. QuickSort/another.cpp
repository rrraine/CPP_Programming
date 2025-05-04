#include <iostream>
#include <cstdlib>
using namespace std;

int* arr;
int n;
void print();
void sort_pivot(int start, int end);

int main(void){
    cout << "Enter the number of elements: ";
    cin >> n;

    arr = (int*) malloc (n * sizeof(int));
    for (int i = 0; i < n; i++){
        cout << "Enter element " << i + 1 << ": ";
        cin >> arr[i];
    }

    sort_pivot(0, n-1);
    cout << "Finish: ";
    print();
}


void sort_pivot(int start, int end){
    cout << "Sorting: "<< start << " and " << end << endl;

    // 1. identify pivot
    int pivot = start++;

    // 2. go through elements,
    // swap start and current element if pivot > arr[i]
    for (int i = start; i <= end; i++){
        if (arr[pivot] > arr[i]){
            cout << "Swapping: " << arr[start] << " and " << arr[i] << endl;
            swap(arr[start], arr[i]);
            // increment start after swap
            if (start++ != i){ // means no swapping happened as start and i are same
                print();
            }
        }
    }

    // 3. swap pivot to the start - 1
    if (pivot < start - 1){
        swap(arr[pivot], arr[start-1]);
        print();
    }

    // 4. recurse left partition, if any
    if (pivot < start -2){
        cout << "Left partition of " << arr[start -1 ] << endl;
        sort_pivot(pivot, start - 2);
    }

    // 5. right partition
    if (end > start){
        cout << "Right partition of " << arr[start-1] << endl;
        sort_pivot(start, end);
    }
}

void print(){
    cout << "[ ";
    for (int i = 0; i < n; i++){
        cout << arr[i] << " ";
        if (i < n-1){
            cout << ", ";
        }
    }
    cout << "]" << endl;
}