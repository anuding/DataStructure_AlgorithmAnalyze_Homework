
/*
* -----------------------------------------------------------
*  Copyright (c) 2017 anuding.github.io All rights reserved.
* -----------------------------------------------------------
*
*        创建者：  anuding
*      创建时间：  2017/10/30 10:43:42
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
#define N 10000
static long long int swaptimes = 0;
static long long int comparetimes = 0;
static double totaltime;
static clock_t start, finish;

using namespace std;

template <typename E>
void selsort(E A[], int n) { //传入待排序序列和序列的大小
	for (int i = 0; i<n - 1; i++) { 
		int lowindex = i; // 保存记录
		for (int j = n - 1; j>i; j--) // 在未排序元素中寻找最大的
			if ((comparetimes++)&&(A[j]> A[lowindex]))
				lowindex = j; // 只替换记录
		swap(A[i], A[lowindex]);//结束循环后才进行交换值
		swaptimes++;
	}

}


int main()
{
	void printresult();

	int *ori, *temp;
	ori = new int[N];//存放在堆上
	srand((unsigned)time(NULL)); //用当前系统时间设置种子
						
	for (int i = 0; i < N; i++)	 //平均情况
	{
		int k = rand() % (N + 1);
		ori[i] = k;

	}
	start = clock();
	selsort<int>(ori, N);
	finish = clock();
	cout << "平均情况下:" << endl;
	printresult();
	cout << endl;




	//最好情况
	for (int i = 0, k = N; i < N; i++, k--)
		ori[i] = k;
	start = clock();
	selsort<int>(ori, N);
	finish = clock();
	cout << "最好情况下:" << endl;
	printresult();





	//最差情况
	for (int i = 0; i < N; i++)
		ori[i] = i;
	start = clock();
	selsort<int>(ori, N);
	finish = clock();
	cout << "最差情况下:" << endl;
	printresult();
	cout << endl;

	//for (int i = 0; i < N; i++)
	//	cout<<ori[i]<<" ";
	getchar();
	return 0;
}

void printresult()
{
	totaltime = (double)(finish - start) / CLOCKS_PER_SEC;
	cout << "此程序的运行时间为" << totaltime << "秒！" << endl;
	cout << "共比较" << comparetimes << "次" << endl;
	cout << "共交换" << swaptimes << "次" << endl;
	swaptimes = 0;
	comparetimes = 0;
	cout << endl;
}