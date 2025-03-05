#include <iostream>
#include <stdexcept>
#include "arraystack.hpp"
#include "linkedList.hpp"
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	Stack* stack;
	cout << "Select Implementation (A/L): ";
	char opt;
	cin >> opt;
	switch (opt) {
		case 'A':
		case 'a':
			stack = new ArrayStack();
			break;
		case 'L':
		case 'l':
			stack = new LinkedListStack();
			break;
		default:
			throw logic_error("Invalid input.");
	}

	int num;
	while (true) {
		cout << "Op: ";
		cin >> opt;
		try {
			switch(opt) {
				case 'a':
					cin >> num;
					stack->push(num);
					break;
				case 'r':
					num = stack->pop();
					cout << "Popped " << num << endl;
					break;
				case 't':
					num = stack->top();
					cout << "Top = " << num << endl;
					break;
				case 's':
					num = stack->size();
					cout << "Size = " << num << endl;
					break;
				case '?':
					num = stack->isEmpty();
					cout << "IsEmpty? " << num << endl;
					break;
				case 'x':
					cout << "Exiting...";
					return 0;
				default:
					cout << "Invalid operation. Try again." << endl;
					break;
			}
		} catch(exception& e) {
			cout << e.what() << endl;
		}
	}

	return 0;
}