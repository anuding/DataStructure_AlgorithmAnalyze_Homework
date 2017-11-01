#include <assert.h>
#include <iostream>
using namespace std;
#define defaultSize 100;

template <typename E> class AStack  {
private:
	int maxSize; // Maximum size of stack
	int top; // Index for top element
	E *listArray; // Array holding stack elements
public:
	AStack(int size = defaultSize) // Constructor
	{
		maxSize = size; top = 0; listArray = new E[size];
	}
//	˜AStack() { delete[] listArray; } // Destructor
	void clear() { top = 0; } // Reinitialize

	void print()
	{
		if (top <= 0)
			cout << "Stack is empty";
		for (int i = 0; i < top; i++)
			cout << listArray[i] << " ";
		cout << endl;
	}
	void push(const E& it) { // Put "it" on stack
		assert(top != maxSize, "Stack is full");
		listArray[top++] = it;
	}
	E pop() { // Pop top element
		assert(top != 0, "Stack is empty");
		return listArray[--top];
	}
	const E& topValue() const { // Return top element
		assert(top != 0, "Stack is empty");
		return listArray[top - 1];
	}
	int length() const { return top; } // Return length
};