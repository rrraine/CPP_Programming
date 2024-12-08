#include <iostream>
#include <string>
#include <vector>
#include "arraystack.hpp" // Assuming ArrayStack is implemented correctly
using namespace std;

int main() {
    Stack* stack = new ArrayStack(); // Use the ArrayStack class
    string input;
    int n1, n2, res;

    cout << "Enter numbers or operators (+, -, *, /). Type 'x' to exit.\n";

    do {
        cout << "Enter: ";
        cin >> input;

        if (input == "+" || input == "-" || input == "*" || input == "/") {
            // Ensure the stack has at least 2 elements for valid operations
            if (stack->size() < 2) {
                cout << "Error: Not enough operands in the stack.\n";
                continue;
            }

            // Pop top two elements
            n1 = stack->top();
            stack->pop();
            n2 = stack->top();
            stack->pop();

            // Perform the operation
            if (input == "+") {
                res = n2 + n1;
            } else if (input == "-") {
                res = n2 - n1;
            } else if (input == "*") {
                res = n2 * n1;
            } else if (input == "/") {
                if (n1 == 0) {
                    cout << "Error: Division by zero.\n";
                    stack->push(n2);
                    stack->push(n1);
                    continue;
                }
                res = n2 / n1;
            }

            // Push the result back to the stack
            stack->push(res);

        } else if (input == "x") {
            // Exit command
            if (stack->isEmpty()) {
                cout << "Stack is empty. Nothing to display.\n";
            } else {
                cout << "Answer is " << stack->pop() << endl;
            }
            break;

        } else {
            // Assume the input is a number, try to convert and push
            try {
                int num = stoi(input);
                stack->push(num);
            } catch (exception& e) {
                cout << "Invalid input. Please enter a number or operator.\n";
            }
        }

    } while (input != "x");

    // Clean up
    delete stack;
    return 0;
}
