
/*
* -----------------------------------------------------------
*  Copyright (c) 2017 anuding.github.io All rights reserved.
* -----------------------------------------------------------
*
*        �����ߣ�  anuding
*      ����ʱ�䣺  2017/11/5 12:29:09
*          CLR��  4.0.30319.42000
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
	cout << "�ڵ���:"<<test.n() << endl;
	cout << "����:" << test.e() << endl<<endl;
	//���ñ�
	cout << "����3��ȨΪ1�ı�...(1,2),(1,3),(2,3)" << endl<<endl;
	test.setEdge(1, 2, 1);
	test.setEdge(3, 1, 1);
	test.setEdge(1, 3, 1);
	test.setEdge(2, 3, 1);
	cout << "�ڵ���:" << test.n() << endl;
	cout << "����:" << test.e() << endl<<endl;


	for (int i = 0; i < 6; i++)
		cout << "�ڵ�" << i << "�ĵ�һ���ھ�:" << test.first(i) << endl;
	cout << endl;
	//cout << test.first(4);
	//cout << "�ӽڵ�1��ʼDFS:";
	//test.DFS(&test,1);//�ӽڵ�1��ʼ����


	//for (int i = 0; i < 6; i++)
	//	cout << test.getMark(i) << " ";
	//cout << endl;
	//
	//
	//cout << "�������...";
	//for (int i = 0; i < 6; i++)
	//	test.setMark(i,0);
	//cout << endl << endl;

	//AQueue<int> Q;
	//cout << "�ӽڵ�1��ʼBFS:";
	//test.BFS(&test, 1,&Q);//�ӽڵ�1��ʼ����
	//for (int i = 0; i < 6; i++)
	//	cout << test.getMark(i) << " ";


	getchar();
    return 0;
}

