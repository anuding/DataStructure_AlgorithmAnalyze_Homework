#include "LQueue.h"
using namespace std;

int main()
{

	LQueue<int> lq1;
	lq1.enqueue(12);
	lq1.enqueue(32);
	lq1.enqueue(123122);
	lq1.enqueue(213);
	lq1.enqueue(99);
	
	lq1.print();
	lq1.dequeue();
	lq1.print();
	lq1.enqueue(666);
	lq1.print();
	return 0;
}