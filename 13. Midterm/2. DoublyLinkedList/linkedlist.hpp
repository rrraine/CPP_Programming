#include <bits/stdc++.h>
#include "list.hpp"
#include "node.hpp"

using namespace std;

class LinkedList : public List{

    int _size;
    node* head;
    node* tail;
    
    void addBetween(node* curr, node* prev, int num){
        node* n = new node();
        n->elem = num;
        n->prev = prev;
        n->next = curr;
        curr->prev = n;
        prev->next = n;
        
    }
    
    void removeBetween(node* curr){
         if (curr == head || curr == tail) return;
        curr->prev->next = curr->next;
        curr->next->prev = curr->prev;
        _size--;
        delete curr;
    }
    
    public:
    
    LinkedList(){
        head = new node();
        tail = new node();
        head->next = tail;
        tail->prev = head;
        _size = 0;
    }
    
    void insert(int num){
        
        addBetween(tail, tail->prev, num);
        _size++;
    }
    
    int get(int pos){
        
        if (pos < 0 || pos > _size) throw logic_error("Invalid position");
        node* curr = head->next;
        
        for (int i = 1; i < pos; i++){
            curr = curr->next;
        }
        return curr->elem;
        
    }
    
    int remove(int num){
        node* curr = head->next;
        int pos = -1;
        
        for (int i = 0; i < _size; i++){
            if (curr->elem == num){
                pos = i + 1;
                removeBetween(curr);
                return pos;
            }
            
            curr = curr->next;
        }
        
        
        return 0;
    }
    
    void print(){
        
        node* curr = head->next;
        if (isEmpty()) {
            cout << "FROM HEAD: (none)" << endl;
            cout << "FROM TAIL: (none)" << endl;
            return;
            
        }
        cout << "FROM HEAD: ";
        
        while(curr != tail){
            cout << curr->elem;
            if (curr->next != tail) cout << " -> ";
            curr = curr->next;
        }
        
        cout << endl;
        
        curr = tail->prev;
        cout << "FROM TAIL: ";
        while(curr != head){
            cout << curr->elem;
            if (curr->prev != head) cout << " <- ";
            curr = curr->prev;
        }
        cout << endl;
    }
    
    int size(){
        return _size;
    }
    
    bool isEmpty(){
        return _size == 0;
    }
    
    void addAt(int num, int pos){
        
        if (pos < 1 || pos > _size + 1) throw logic_error ("Invalid position");
        
        node* curr = head->next;
        for (int i = 1; i < pos; i++){
            curr = curr->next;
        }
        
        addBetween(curr, curr->prev, num);
        _size++;
    }
    
    int removeAt(int pos){
        
        if (pos < 1 || pos > _size) throw logic_error("Invalid position");
        int num = 0;
        node* curr = head->next;
        for (int i = 1; i < pos ; i++){
            curr = curr->next;
                        
        }
        num = curr->elem;
        removeBetween(curr);
        return num;
    }
    

};