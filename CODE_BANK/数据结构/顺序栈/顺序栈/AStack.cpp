#include "AStack.h"
using namespace std;

int main()
{
	AStack<int> as1;
	as1.push(1);
	as1.push(6);
	as1.push(34);
	as1.push(0);
	as1.push(99);
	as1.print();
	as1.pop();
	as1.print();
	return 0;
}