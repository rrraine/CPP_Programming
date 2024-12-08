#include<iostream>
#include<stack>
#include<string>
#include "arraystack.hpp"
using namespace std;

// TODO implement this method.
// Use the ArrayStack to perform the stack operations needed.
int is_balanced_parentheses(string str){
    ArrayStack stack;

    for(char c : str){
        if (c == '(' || c == '{' || c == '['){ // push opening parentheses
            stack.push(c);
        } else if (c == ')' || c == '}' || c == ']'){
            if (stack.isEmpty()){ // check if stack is empty (w/o opening parentheses)
                return 3; // lacks opening parentheses
            }

            char topElement = stack.top();
            stack.pop();

            if ((c == ')' && topElement != '(') || (c == '}' && topElement != '{') || (c == ']' && topElement != '[')){ // check is dili same ang parentheses
                return 1; // mismatch
            }
        }

    }

    return stack.isEmpty() ? 0 : 2;
    
}

int main(){
    string str;
    cout << "Enter a string with parentheses: ";
    cin >> str;
    int res = is_balanced_parentheses(str);
    switch(res) {
        case 0:
            cout << "The parentheses are balanced!" << endl;
            break;
        case 1:
            cout << "The parentheses are not balanced due to mismatch!" << endl;
            break;
        case 2:
            cout << "The parentheses are not balanced due to missing closing parentheses!" << endl;
            break;
        case 3:
            cout << "The parentheses are not balanced due to missing opening parentheses!" << endl;
            break;
    }
    return 0;
}