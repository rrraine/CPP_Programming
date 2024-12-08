// #pragma once

#ifndef LIST_HPP
#define LIST_HPP


#include <iostream>

class List {
    public:
    virtual void add(int) = 0;
    virtual int get(int pos) = 0;
    virtual int remove(int num) = 0;
    virtual void print() = 0;
};

#endif // LIST_HPP