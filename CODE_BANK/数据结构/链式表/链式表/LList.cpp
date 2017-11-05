#include "LList.h"
#include <time.h>
#include <stdio.h>



int main(int grgc, char** argv) {
	int const listsize = 6;
	LList<int> list1;
	//LList<int> list2(listsize);
	//srand((unsigned int)time(NULL));
	list1.append(11);
	list1.append(23);
	list1.append(14541);
	list1.append(345);
	list1.append(89);
	list1.append(121);
	list1.next();
	list1.print();
	list1.next();
	list1.next();
	//list1.remove();
	//list1.print();
	getchar();


	return 0;

}
