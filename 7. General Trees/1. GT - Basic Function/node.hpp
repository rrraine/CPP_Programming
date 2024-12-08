#include <cstdlib>

struct node {
	node **children;
	int num_child;
	node *parent;
	int elem;


    int depth() {
        if (parent == nullptr) return 0;

        return parent->depth() + 1;
	}


    int height() {
        if (num_child == 0) return 0;
        int maxHeight = 0;

        for (int i = 0; i < num_child; i++){
            int initialHeight = children[i]->height();
            if (initialHeight > maxHeight){
                maxHeight = initialHeight;
            }
        }
        return maxHeight + 1;
    }
};