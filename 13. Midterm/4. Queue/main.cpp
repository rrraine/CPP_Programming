#include <iostream>
#include <stdexcept>
#include "arrayqueue.hpp"
#include "linkedlistqueue.hpp"
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	Queue* queue;
	cout << "Select Implementation (A/L): ";
	char opt;
	cin >> opt;
	switch (opt) {
		case 'A':
		case 'a':
			queue = new ArrayQueue();
			break;
		case 'L':
		case 'l':
			queue = new LinkedListQueue();
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
				case 'e':
					cin >> num;
					queue->enqueue(num);
					break;
				case 'd':
					num = queue->dequeue();
					cout << "Dequeued " << num << endl;
					break;
				case 'f':
					num = queue->first();
					cout << "First = " << num << endl;
					break;
				case 's':
					num = queue->size();
					cout << "Size = " << num << endl;
					break;
				case '?':
					num = queue->isEmpty();
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