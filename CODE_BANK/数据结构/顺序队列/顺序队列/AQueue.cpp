#include "AQueue.h"
using namespace std;

int main()
{
	AQueue<int> aq1;
	aq1.enqueue(12);
	aq1.enqueue(32);
	aq1.enqueue(123122);
	aq1.enqueue(213);
	aq1.enqueue(99);
	aq1.print();
	aq1.dequeue();
	aq1.print();
	aq1.enqueue(666);
	aq1.print();
	return 0;
}