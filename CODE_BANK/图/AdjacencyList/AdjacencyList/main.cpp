
/*
* -----------------------------------------------------------
*  Copyright (c) 2017 anuding.github.io All rights reserved.
* -----------------------------------------------------------
*
*        创建者：  anuding
*      创建时间：  2017/11/5 12:29:09
*          CLR：  4.0.30319.42000
*
*/




#include <cstdlib>
#include <ctime>
#include <windows.h>
#include<time.h>
#include<stdio.h>
#include<stdlib.h>
#include "Graphl.h"

using namespace std;
int main()
{
	Graphl test(6);
	cout << "节点数:"<<test.n() << endl;
	cout << "边数:" << test.e() << endl<<endl;
	//设置边
	cout << "设置3条权为1的边...(1,2),(1,3),(2,3)" << endl<<endl;
	test.setEdge(1, 2, 1);
	test.setEdge(3, 1, 1);
	test.setEdge(1, 3, 1);
	test.setEdge(2, 3, 1);
	cout << "节点数:" << test.n() << endl;
	cout << "边数:" << test.e() << endl<<endl;


	for (int i = 0; i < 6; i++)
		cout << "节点" << i << "的第一个邻居:" << test.first(i) << endl;
	cout << endl;
	//cout << test.first(4);
	//cout << "从节点1开始DFS:";
	//test.DFS(&test,1);//从节点1开始遍历


	//for (int i = 0; i < 6; i++)
	//	cout << test.getMark(i) << " ";
	//cout << endl;
	//
	//
	//cout << "标记清零...";
	//for (int i = 0; i < 6; i++)
	//	test.setMark(i,0);
	//cout << endl << endl;

	//AQueue<int> Q;
	//cout << "从节点1开始BFS:";
	//test.BFS(&test, 1,&Q);//从节点1开始遍历
	//for (int i = 0; i < 6; i++)
	//	cout << test.getMark(i) << " ";


	getchar();
    return 0;
}

