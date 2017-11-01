#include <iostream>
#include <assert.h>
#include "Link.h"
using namespace std;

#define defaultSize 100

template <typename E> class LStack  {
private:
	Link<E>* top; // Pointer to first element
	int size; // Number of elements
public:
	LStack(int sz = defaultSize) // Constructor
	{
		top = NULL; size = 0;
	}
	//˜LStack() { clear(); } // Destructor
	void print()
	{
		Link<E>* temp = top;
		for (int i = 0; i<size; i++) {
			cout << temp->element << " ";
			temp = temp->next;
		}
		
		cout << endl;
	}
	void clear() { // Reinitialize
		while (top != NULL) { // Delete link nodes
			Link<E>* temp = top;
			top = top->next;
			delete temp;
		}
		size = 0;
	}
	void push(const E& it) { // Put "it" on stack
		top = new Link<E>(it, top);
		size++;
	}
	E pop() { // Remove "it" from stack
		assert(top != NULL, "Stack is empty");
		E it = top->element;
		Link<E>* ltemp = top->next;
		delete top;
		top = ltemp;
		size--;
		return it;
	}
	const E& topValue() const { // Return top value
		assert(top != 0, "Stack is empty");
		return top->element;
	}
	int length() const { return size; } // Return length
};