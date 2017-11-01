#include "AList.h"
using namespace std;

int main()
{
	AList<int> al1;
	al1.append(11);
	al1.append(23);
	al1.append(14541);
	al1.append(345);
	al1.append(89);
	al1.append(121);
	al1.print();
	al1.next();
	al1.next();
	al1.remove();
	al1.print();
	return 0;
}