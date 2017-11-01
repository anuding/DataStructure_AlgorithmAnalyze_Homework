#include <iostream>
#include "Queue.h"
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
using namespace std;
// Array-based queue implementation
template <typename E> class DoubleQueue  {
private:
	int maxSize; // Maximum size of queue
	int front; // Index of front element
	int rear; // Index of rear element
	E *listArray; // Array holding queue elements
	int size =10;
public:
	DoubleQueue() { // Constructor
									 // Make list array one position larger for empty slot
		maxSize = size + 1;
		rear = 0; front = 1;
		listArray = new E[maxSize];
	}
//	˜DoubleQueue() { delete[] listArray; } // Destructor
	void clear() { rear = 0; front = 1; } // Reinitialize
	
	void print()
	{
		for (int i = front; i <=rear; i++)
			cout << listArray[i] << "  ";
		cout << endl;
	}
	void enqueue_head(const E& it) { // Put "it" in queue
		
			listArray[front - 1] = it;
			front = front - 1;
		
	}

	void enqueue_tail(const E& it) { // Put "it" in queue
		assert(((rear + 2) % maxSize) != front, "Queue is full");
		rear = (rear + 1) % maxSize; // Circular increment
		listArray[rear] = it;
	}

	E dequeue_head() { // Take element out
		assert(length() != 0, "Queue is empty");
		E it = listArray[front];
		front = (front + 1) % maxSize; // Circular increment
		return it;
	}

	E dequeue_tail() { // Take element out
		assert(length() != 0, "Queue is empty");
		E it = listArray[rear];
		rear = (rear - 1) % maxSize; // Circular increment
		return it;
	}

	const E& frontValue() const { // Get front value
		assert(length() != 0, "Queue is empty");
		return listArray[front];
	}

	virtual int length() const // Return length
	{
		return ((rear + maxSize) - front + 1) % maxSize;
	}
};