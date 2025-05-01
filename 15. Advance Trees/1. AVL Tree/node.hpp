#include <algorithm>
#include <cmath>
using namespace std;
struct node {
    node* parent;
    node* right;
    node* left;
    int elem;

    // TODO paste your height method here
    int height() {
        // int left_, right_;
        // return 1 + max(left_ ? left->height() : 0, right_ ? right->height() : 0);
        
         
        if(!left && !right){
            return 1;
        }
        
        if (!left){
            return 1 + right->height();
        }
        
        if (!right){
            return 1 + left->height();
        }
        
        return 1 + fmax(right->height(), left->height());
    
    }
    
   
};