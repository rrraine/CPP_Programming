#include "node.hpp"
#include <iostream>
#include <cstdlib>
using namespace std;

class GenTree {

	public:
	virtual node* addRoot(int) = 0;
	virtual node* addChild(node*, int) = 0;
	virtual void remove(node*) = 0;
	virtual int getSize() = 0;
	virtual node* getRoot() = 0;
    
    // tree traversals
    virtual void preOrderTraversal() = 0;
    virtual void postOrderTraversal() = 0;
    virtual void inOrderTraversal() = 0;
    
    virtual void print() = 0;

};