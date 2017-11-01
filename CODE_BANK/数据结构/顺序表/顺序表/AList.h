#include <iostream>
#include <assert.h>
using namespace std;
#define defaultSize 100
template <typename E> // Array-based list implementation
class AList {
private:
	int maxSize; // Maximum size of list
	int listSize; // Number of list items now
	int curr; // Position of current element
	E* listArray; // Array holding list elements
public:
	AList(int size = defaultSize) { // Constructor
		maxSize = size;
		listSize = curr = 0;
		listArray = new E[maxSize];
	}
public:
//	˜AList() { } // Destructor
	void clear() { // Reinitialize the list
		delete[] listArray; // Remove the array
		listSize = curr = 0; // Reset the size
		listArray = new E[maxSize]; // Recreate array
	}

	void print()
	{
		if (listSize <= 0)
			cout << "AList is empty!" << endl;
		for (int i = 0; i < listSize; i++)
			cout << listArray[i] << " ";
		cout << endl;
	}
	// Insert "it" at current position
	void insert(const E& it) {
		assert(listSize < maxSize, "List capacity exceeded");
		for (int i = listSize; i>curr; i--) // Shift elements up
			listArray[i] = listArray[i - 1]; // to make room
		listArray[curr] = it;
		listSize++; // Increment list size
	}
	void append(const E& it) { // Append "it"
		assert(listSize < maxSize, "List capacity exceeded");
		listArray[listSize++] = it;
	}
	// Remove and return the current element.
	E remove() {
		assert((curr >= 0) && (curr < listSize), "No element");
		E it = listArray[curr]; // Copy the element
		for (int i = curr; i<listSize - 1; i++) // Shift them down
			listArray[i] = listArray[i + 1];
		listSize--; // Decrement size
		return it;
	}
	void moveToStart() { curr = 0; } // Reset position
	void moveToEnd() { curr = listSize; } // Set at end
	void prev() { if (curr != 0) curr--; } // Back up
	void next() { if (curr < listSize) curr++; } // Next
												 // Return list size
	int length() const { return listSize; }
	// Return current position
	int currPos() const { return curr; }
	// Set current list position to "pos"
	void moveToPos(int pos) {
		assert((pos >= 0) && (pos <= listSize), "Pos out of range");
		curr = pos;
	}
	const E& getValue() const { // Return current element
		assert((curr >= 0) && (curr<listSize), "No current element");
		return listArray[curr];
	}
};