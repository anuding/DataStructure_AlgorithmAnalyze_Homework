#include "doublequeue.h"
using namespace std;

int main()
{
	DoubleQueue<int> dqueue1;
	//dqueue1.enqueue_tail(5);
	//dqueue1.enqueue_tail(6);
	//dqueue1.enqueue_tail(7);
	//dqueue1.enqueue_tail(5);
	//dqueue1.enqueue_tail(5);
	//dqueue1.print();
	//dqueue1.dequeue_head();
	//dqueue1.print();
	dqueue1.enqueue_head(99);
	dqueue1.enqueue_head(2);
	dqueue1.enqueue_head(3);
	dqueue1.enqueue_head(4);
	dqueue1.print();
	dqueue1.enqueue_head(5);
	dqueue1.print();
//	dqueue1.dequeue_tail();
	
	return 0;
}