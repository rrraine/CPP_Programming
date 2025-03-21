#pragma once
class Stack {
	public:
		virtual void push(int) = 0;
		virtual int pop() = 0;
		virtual int top() = 0;
		virtual int size() = 0;
		virtual bool isEmpty() = 0;
};