
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
	//cout << "设置3条权为1的边...(1,2),(1,3),(2,3)" << endl<<endl;
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
	cout << "边数:" << test.e() << endl<<endl;
	test.printgrpah();
	//cout << "输出n值表示该节点没有邻居节点"<<endl;
	/*for (int i = 0; i < test.n(); i++)
	{
		cout << i+1<< "->";
		int temp = i,
			temp1= test.first(temp);
		if (temp1 < test.n())
			cout << temp1+1<< "->";
		while (test.next(temp, temp1)<test.n())
		{
			cout << test.next(temp, temp1)+1<<"->";
			temp1 = test.next(temp, temp1);
		}
		cout << "/" << endl;
	}
		*/
		
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

