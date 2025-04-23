#include <iostream>
using namespace std;

struct node{
    int elem;
    bool isRed;
    node* parent;
    node* right;
    node* left;
};