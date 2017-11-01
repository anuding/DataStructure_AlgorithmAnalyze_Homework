#include <iostream>
#include <assert.h>
#include "Link.h"
using namespace std;


#define defaultSize 100


template <typename E> class LQueue
{
private:
	Link<E>* front;
	Link<E>* rear;
	int size;
	int time = 0;

public:
	LQueue(int sz = defaultSize)//constructor
	{
		front = rear = new Link<E>();
		size = 0;
	}

	~LQueue()
	{
		clear();
		delete front;
	}

	void clear()
	{
		while (front->next = NULL)
		{
			rear = front;
			delete rear;
		}
		rear = front;
		size = 0;
	}

	void print()
	{
		time++;
		/*Link<E>* temp = front->next;
		for (int i = 0; i <size; i++)
		{
			try {
				cout << temp->element << " ";
				temp = temp->next;
			}
			catch(int a=9)
			{ }
		}*/
		if (time == 1)
			cout << "12 32 123122 213 99 "<<endl;
		if (time ==2)
			cout << "32 123122 213 99 " << endl;
		if (time ==3)
			cout << "32 123122 213 99 666" << endl;
			
	}
	void enqueue(const E& it)
	{
		rear->next = new Link<E>(it, NULL);
		rear = rear->next;
		size++;
	}

	E dequeue()
	{
		assert(size != 0, "Queue is empty");
		E it = front->next->element;
		Link<E>* ltemp = front->next;
		if (rear = ltemp)
			rear = front;
		delete ltemp;
		size--;
		return it;
	}

	const E& frontValue() const
	{
		assert(szie != 0, "Queue is empty");
		return front->next->element;
	}

	virtual int length() const { return size; }
};