
/*
* -----------------------------------------------------------
*  Copyright (c) 2017 anuding.github.io All rights reserved.
* -----------------------------------------------------------
*
*        创建者：  anuding
*      创建时间：  11/16/2017 4:16:08 PM
*          CLR：  4.0.30319.42000
*
*/



#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>
#include<time.h>
#include<stdio.h>
#include<stdlib.h>
#include "Graphm.h"
using namespace std;
int main()
{
	Graphm test(6);
	cout << "节点数:" << test.n() << endl;
	cout << "边数:" << test.e() << endl << endl;
	test.setEdge(0, 1, 10);
	test.setEdge(0, 5, 2);
	test.setEdge(0, 3, 20);
	test.setEdge(1, 2, 3);
	test.setEdge(1, 3, 5);
	test.setEdge(2, 4, 15);
	test.setEdge(3, 5, 10);
	test.setEdge(3, 4, 11);
	test.setEdge(5, 4, 3);

	cout << "节点数:" << test.n() << endl;
	cout << "边数:" << test.e() << endl << endl;
	test.print();
	

	cout << endl;
	getchar();
    return 0;
}

