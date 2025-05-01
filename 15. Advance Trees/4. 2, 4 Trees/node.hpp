#include <iostream>
#include <climits>
#include <set>

struct node {
	node* parent;
	int keys[4];
	node** children = (node**) calloc (5, sizeof(node*));
	int children_size = 0;
	int size = 0;
	
	
    bool searchKey(int num){
        for (int i = 0; i < 4; i++){
            if (keys[i] == num){
                return true;
            }
        }
        
        return false;
    }
    
    void removeKey(int num){
        for (int i = 0; i < size-1; i++){
            if (keys[i] == num){
                keys[i] = keys[i+1];
                size--;
            }
        }
        
    }
    void addKey(int num){
        
        if (size == 0){
            keys[0] = num;
            size++;
            return;
        }
        
        // if (size == 4){
        //     return;
        // }
        
        // int i;
        
        // for (int i = size - 1;i >= 0 && num < keys[i]; i--){
        //     keys[i + 1] = keys[i];
        // }
        
        // keys[++i] = num;
        // return ++size != 4;
        
        // add and sort them accordingly
        for (int i = 0; i< size; i++){
            if (num < keys[i]){
                for (int j = size; j > i; j--){
                    keys[j] = keys[j-1];
                }
                
                keys[i] = num;
                size++;
                return;
            }
            
            // keys[i] = num;
            // size++;
            // return;
        }
        
        keys[size++] = num;
    }
    
    bool isFull(){
        return size == 4;
    }
    
    bool isMaxChildren(){
        return children_size ==5;
    }
    
    void setChildren(node* left, node* right, node* curr){
        // for (int i = size; i > pos; i--){
        //     children[i+1] = children[i];
        // }
        
        // children[pos] = wp;
        // children[pos+1] = w2p;
        
        if (children_size == 0){
            children[0] = left;
            children[1] = right;
            children_size += 2;
        } else {
            
            for (int i = 0; i  < children_size; i++){
                
                if (curr == children[i]){
                    for (int j = children_size; j > i;  j--){
                        children[j] = children[j-1];
                    }    
                    
                    children[i] = left;
                    children[i+1] = right;
                    break;
                }
                
                
            }
            
            children_size++;
            
        }
        
        
        // edge cases
        
        if (curr->children_size != 0){
            adoptChild(left, 0, curr, 0);
            adoptChild(left, 1, curr, 1);
            adoptChild(left, 2, curr, 2);
            
            adoptChild(right, 0, curr, 3);
            adoptChild(right, 1, curr, 4);
        }
        
        left->parent = this;
        right->parent = this;
        
    }
    
    void adoptChild(node* newPar, int  pos1, node* oldPar, int pos2){
        node* child = oldPar->children[pos2];
        
        newPar->children[pos1] = child;
        child->parent = newPar;
        newPar->children_size++;
    }
    
    // int indexOf(node* child){
    //     for (int i = 0; i <= size; i++){
    //         if (child == children[i])
    //             return i;
    //     }
    //     return -1;
    // }
};