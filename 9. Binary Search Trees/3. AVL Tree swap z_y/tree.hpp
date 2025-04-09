#include <bits/stdc++.h>
#include "node.hpp"
using namespace std;

class tree{

    public: 

    virtual void zigleft(node*n) = 0;
    virtual void zigright(node*n) = 0;
    virtual bool insert(int num) = 0;
    virtual bool remove(int num) = 0;
    virtual void print() = 0;

};
