
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
	//ÉèÖÃ±ß
	cout << "初始化三条边...(1,2),(1,3),(2,3)" << endl << endl;
	test.setEdge(1, 2, 1);
	test.setEdge(3, 1, 1);
	test.setEdge(1, 3, 1);
	test.setEdge(2, 3, 1);
	cout << "节点数:" << test.n() << endl;
	cout << "边数:" << test.e() << endl << endl;

	//n代表没有邻居
	for (int i = 0; i < 6; i++)
		cout << "" << i << ":" << test.first(i) << endl;
	cout << endl;
    return 0;
}

