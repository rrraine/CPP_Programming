#include <iostream>
#include "linkedlist.hpp"
#include <bits/stdc++.h>

LinkedList* mergeSort(LinkedList*); // declare mergeSort function

// WARNING! Do not modify this main function!
// Doing so will nullify your score for this activity.
int main(void) {
    LinkedList* list = new LinkedList();

    int length;
    cout << "Input length: ";
    cin >> length;

    int input;
    for (int i = 0; i < length; i++) {
        cout << "Enter element " << i + 1 << ": ";
        cin >> input;
        list->add(input);
    }
    list->print();

    list = mergeSort(list);
    return 0;
};

node* getHalf(LinkedList* list){
    node* slow = list->head;
    node* fast = list->head;

    while (fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
    }

    return !fast ? slow : slow->next;

}

LinkedList* mergeSort(LinkedList* list){
    // 0. base case
    if (list->size() <= 1){
        return list;
    }

    // 1. split the list to two
    LinkedList* left = new LinkedList();
    LinkedList* right = new LinkedList();
    node* mid = getHalf(list);
    node* curr = list->head;
    // add element to left and right list

    for (; curr != mid; curr = curr->next){
        left->add(curr->element);
    }

    for (; curr; curr = curr->next){
        right->add(curr->element);
    }


    
    // 2. recursive

    cout << "Left list: ";
    left->print();
    left = mergeSort(left);

    cout << "Right list: ";
    right->print();
    right = mergeSort(right);

    // 3. merge/combine

    LinkedList* merged = new LinkedList();
    node* currLeft = left->head;
    node* currRight = right->head;

    while (currLeft && currRight){
        if (currLeft->element < currRight->element){
            merged->add(currLeft->element);
            currLeft = currLeft->next;
        } else {
            merged->add(currRight->element);
            currRight = currRight->next;
        }
    }

    while (currLeft){
        merged->add(currLeft->element);
        currLeft = currLeft->next;
    }

    while (currRight){
        merged->add(currRight->element);
        currRight = currRight->next;
    }


    // 4. print
    cout << "SORTED: ";
    merged->print();
    return merged;
}