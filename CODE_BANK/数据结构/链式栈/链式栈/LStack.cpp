#include "LStack.h"

int main()
{
	LStack<int> ls1;
	ls1.push(1);
	ls1.push(43);
	ls1.push(34);
	ls1.push(33);
	ls1.push(5);
	ls1.push(981);
	ls1.print();
	ls1.pop();
	ls1.print();
	return 0;
}