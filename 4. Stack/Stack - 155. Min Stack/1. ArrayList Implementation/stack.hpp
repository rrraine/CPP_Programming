// TODO change this to handle char elements

class Stack {
	public:
	virtual void push(int c) = 0;
	virtual int pop() = 0;
	virtual int top() = 0;
	virtual int size() = 0;
    virtual int getMin() = 0;
	virtual bool isEmpty() = 0;
	virtual void print() = 0;
};