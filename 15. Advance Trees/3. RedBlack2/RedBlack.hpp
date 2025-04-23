#pragma once
#include <iostream>
using namespace std;


class RedBlack{
    public:
    virtual void insert(int elem) = 0;
    virtual void print() = 0;
    virtual bool search(int elem) = 0;
    virtual void remove(int elem) = 0;
    virtual ~RedBlack(){};
};