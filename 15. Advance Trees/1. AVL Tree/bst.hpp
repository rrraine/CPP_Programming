#include "mybinarytree.hpp"

class BST {
	BinaryTree* tree = new MyBinaryTree();

	public:
	bool search(int num) {
		return search_node(tree->getRoot(), num);
	}

	bool search_node(node* n, int num) {
		if (n == NULL) {
			return false;
		}
		if (n->elem == num) {
			return true;
		}
		if (num > n->elem) {
			// proceed to right
			return search_node(n->right, num);
		} else {
			return search_node(n->left, num);
		}
	}

	node* insert(int num) {
		node* n = tree->getRoot();
		if (n == NULL) {
			return tree->addRoot(num);
		}
		return insert_node(n, num);
	}

	node* insert_node(node* n, int num) {
		if (n == NULL) {
			return NULL;
		}
		if (n->elem == num) {
			return NULL;
		}
		if (num > n->elem) {
			if (!n->right) {
				return tree->addRight(n, num);
			} else {
				return insert_node(n->right, num);
			}
		} else {
			if (!n->left) {
				return tree->addLeft(n, num);
			} else {
				return insert_node(n->left, num);
			}
		}
	}

    bool remove(int num) {
        return remove_node(tree->getRoot(), num);
    }

	bool remove_node(node* n, int num) {
		if (n == NULL) {
			return false;
		}
		if (n->elem == num) {
            if (n->left && n->right) {
                node* r = n->right;
                while (r->left) {
                    r = r->left;
                }
                int rem = tree->remove(r);
                n->elem = rem;
            } else {
    			tree->remove(n);
            }
            return true;
		}
		if (num > n->elem) {
			return remove_node(n->right, num);
		} else {
			return remove_node(n->left, num);
		}
	}
	
	   // if (left > right){
        //     par = gp->left;
            
        // } else {
        //     par = gp->right;
        // }

    // GIVEN the grandparent (or z), find the parent (or y), and the child (or x).
    bool restructure(node* gp) {
        node* par; // parent
        // TODO find parent
        
        
        
        int left = gp->left == NULL ? 0 : gp->left->height();
        int right = gp->right == NULL ? 0 : gp->right->height();
        
        if (left > right){
            par = gp->left;
        } else {
            par = gp->right;
        }
        

        // This is an indicator of the placement of grandparent to parent (gtop)
        bool gtop_right = false;
        if (gp->right == par) {
            gtop_right = true;
        }
        
    
        node* child;
        // TODO find child
        
        
        left = par->left == NULL ? 0 : par->left->height();
        right = par->right == NULL ? 0 : par->right->height();
        
        if(left == right){
            if (gtop_right){
                child = par->right;
            } else {
                child = par->left;
            }
        } else if (left > right){
            child = par->left;
        } else {
            child = par->right;
        }
        
      
        
        // This is an indicator of the placement of parent to child (ptoc)
        bool ptoc_right = false;
        if (par->right == child) {
            ptoc_right = true;
        }
        
     
        // FOR THE FOLLOWING: Write in each of the if statements a console output
        // on its corresponding operation (ZIGLEFT, ZIGRIGHT, ZIGZAGLEFT, or ZIGZAGRIGHT)

        // z
        //  \
        //   y
        //    \
        //     x
        if (gtop_right && ptoc_right) {
            // TODO call to either zigleft or zigright or both
            cout << "ZIGLEFT" << endl;
            zigleft(par);
        }

        // z
        //   \
        //     y
        //    /
        //   x
        else if (gtop_right && !ptoc_right) {
            // TODO call to either zigleft or zigright or both
            cout << "ZIGZAGLEFT"  << endl;
            // zigleft(child);
            zigright(child); //?
            zigleft(child);
        }

        //     z
        //    /
        //   y
        //  /
        // x
        else if (!gtop_right && !ptoc_right) {
            // TODO call to either zigleft or zigright or both
            cout << "ZIGRIGHT"  << endl;
            zigright(par);
        }

        //      z
        //    /
        //  y
        //   \
        //    x
        else {
            // TODO call to either zigleft or zigright or both
            cout << "ZIGZAGRIGHT"  << endl;
            zigleft(child); // ?
            zigright(child);
            
        }

        return true;
    }

    void zigleft(node* curr) {
        tree->zigleft(curr);
    }

    void zigright(node* curr) {
        tree->zigright(curr);
    }

	void print() {
		tree->print();
	}
};


/*

 // if (gtop_right == true){
        //     if (par->right!= nullptr && par->left == nullptr) {
        //         child = par->right;
        //     } else if (par->left != nullptr && par->right == nullptr){
        //         child = par->left;  
        //     } else {
        //         child = par->right;
        //     }
        // } else {
        //      if (par->left && par->right == nullptr) {
        //         child = par->right;
        //     } else if (par->right && par->left == nullptr){
        //         child = par->left;  
        //     } else {
        //         child = par->left;
        //     }
        // }
        
        // if (par->left && par->right){
        //     if (par->left->height() > par->right->height()){
        //         child = par->left;
        //     } else {
        //         child = par->right;
        //     }
        // } else if (par->left && !par->right){
        //     child = par->left;
        // } else {
        //     child = par->right;
        // }
       
        
        // if (gp->right == par){
        //     if (par->right){
        //         child = par->right;
        //     } else {
        //         child = par->left;
        //     }
        // } else {
        //     if (par->left){
        //         child = par->left;
        //     } else {
        //         child =par->right;
        //     }
            
        // }
        
        // if (!gp->right && !gp->left){
        //     return false;
        // } else if (!gp->right && gp->left){
        //     par = gp->left;
        // } else if (gp->right && !gp->left){
        //     par = gp->left;
        // }
*/