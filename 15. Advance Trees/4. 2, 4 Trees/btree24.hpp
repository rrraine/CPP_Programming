#include "node.hpp"
#include <iostream>
using namespace std;

class BTree24 {
	node* root;
    
    node* search(int num){
        node* curr = root;
        
        if(!curr){
            return nullptr;
        }
        
            int i;
            
            // for (i = 0; i < curr->size && num < curr->keys[i]; i++){
            //     if (curr->keys[i] == num){
            //         return curr;
            //     }
            // }
            
            // node* child = curr->children[i];
            // if (!child){
            //     return curr;
            // }
            
            // curr = child;
            
        while(curr->children_size != 0){
            int size = curr->size;
                
            for (int i = 0; i < size; i++){
                if (curr->keys[i] == num){
                    return NULL;
                }
                    
                    // omg  kaingay ni lucky
                if (num < curr->keys[i]){
                    curr = curr->children[i];
                    break;
                } else if(i == size-1) {
                    int last_child = curr->children_size -1;
                    curr = curr->children[last_child];
                }
            }
        }
            
        for (int i = 0; i < curr->size;i++){
            if (curr->keys[i] == num){
                return NULL;
            }
        }
            
        return curr;
        
    }
    
    // void split(node* n){
    //     int middle = n->keys[2];
    //     node* par
        
    //     node* firstChild = new node();
    //     node* secondChild = new node();
        
    //     firstChild->addKey(n->key[0]);
    //     firstChild->addKey(n->key[1]);
    //     n->removeKey(n->key[0]);
    //     n->removeKey(n->key[1]);
    //     secondChild->addKey(n->key[3]);
    //     n->removeKey(n->key[3]);
        
    //     n->setChildren(firstChild, secondChild, -1); // sayop
    // }
    
    
    void split(node* curr){
	    node* left = new node();
	    node* right = new node();
	    
	    left->addKey(curr->keys[0]);
	    left->addKey(curr->keys[1]);
	    
	    right->addKey(curr->keys[3]); // omg ito ra diay
	    
	    
	    node* parent;
	    
	    if (curr == root){
	        parent = new node();
	        parent->addKey(curr->keys[2]);
	        
	        parent->setChildren(left, right, curr);
	        root = parent;
	    } else {
	        
	        parent = curr->parent;
	        parent->addKey(curr->keys[2]);
	        
	        parent->setChildren(left, right, curr);
	        
	        if(parent->isFull()) split(parent);
	    }
	}
	
	public:
	BTree24() {
		root = nullptr;
	}

    
	bool insert(int num) {
	    //return false;
	    
	    if (!root){
	       // root = create_node(num);
	       // root->size++;
	       // return true;
	       
	       root = new node();
	       root->addKey(num);
	       return true;
	    } 
	        node* searchedNode = search(num);
	        
	        
	        if (!searchedNode) return false;
	        
	        searchedNode->addKey(num);
	        
	        
	        // for split or not
	        if (searchedNode->isFull()){
	            split(searchedNode);
	        }
	        
	        return true;
	        
	       // bool ok = searchedNode->addKey(num);
	        
	       // if (ok){
	       //     node* u;
	       //     int pos;
	            
	       //     if (searchedNode == root){
	       //         u = create_node(num);
	       //         root = u;
	       //         pos = 0;
	       //     } else {
	       //         u = searchedNode->parent;
	       //         pos = u->indexOf(searchedNode);
	       //     }
	          //  node* wp = create_node(searchedNode->keys[0]); // fix
	          //  wp->addKey(searchedNode->keys[1]);
	          //  node* w2p = new node(searchedNode->keys[3], u);
	        
	        
	    
	   
	}
	
	

	// WARNING. Do not modify these methods.
    // Doing so will nullify your score for this activity.
	void print_node(string s, node* n) {
		cout << s << ": ";
		for (int i = 0; i < n->size; i++) {
			cout << n->keys[i] << " ";
		}
		cout << endl;
		for (int i = 0; i <= n->size; i++) {
			if (n->children[i]) {
				print_node("Child " + to_string(i+1) + " of " + s,n->children[i]);
			}
		}
	}
    bool check_parent(node* curr, node* par) {
        if (!curr) {
            return true;
        }
        if (curr->parent != par) {
            if (!curr->parent) {
                cout << "Illegal parent of [" << curr->keys[0] << ",...]: NULL -- must be [" << par->keys[0] << ",...]" << endl;
            } else if (!par) {
                cout << "Illegal parent of [" << curr->keys[0] << ",...]: [" << curr->parent->keys[0] << ",...] -- must be NULL" << endl;
            } else {
                cout << "Illegal parent of [" << curr->keys[0] << ",...]: [" << curr->parent->keys[0] << ",...] -- must be [" << par->keys[0] << ",...]" << endl;
            }
            return false;
        }
        bool res = true;
        for (int i = 0; i < curr->size; i++) {
        	res &= check_parent(curr->children[i], curr);
		}
        return res;
    }

	void print() {
		print_node("Root", root);
		check_parent(root, NULL);
	}
};