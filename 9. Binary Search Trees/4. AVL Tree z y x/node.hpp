#pragma ONCE
#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

struct node {

    node* parent;
    node* right;
    node* left; 
    int element;

    int height(){

        return 1 + max(left ? left->height() : 0, right ? right->height() : 0);

    }

};


/*
    int height(){
        if (!this) return 0;
        int left = left ? left->height() : 0;
        int right = right ? right->height() : 0;
        
        
        return 1 + max(left, right);
    }
*/