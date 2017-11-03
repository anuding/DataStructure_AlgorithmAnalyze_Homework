
/*
* -----------------------------------------------------------
*  Copyright (c) 2017 anuding All rights reserved.
* -----------------------------------------------------------
*
*        创建者：  anuding
*      创建时间：  2017/10/23 19:22:57
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
void radixsort(E A[]) 
{
	int box[10][N];//box用来存储每种余数的数据，box[4][0]表示余数为4的第一个数据
	int flag[10] = {0};//flag表示每种余数的数据总量，flag[4]==5表示共有5个余数为4的数据
	int bit = N / 10;
	for (int i = 0; i<N; i++)
	{
		int temp = A[i] % 10;
		box[temp][flag[temp]] = A[i];
		flag[temp]++;
	}
	
	int num=0;
	for(int k=0;k<10;k++)
		for (int i = 0; i < 10; i++)
			for (int j = 0; j < flag[i]; j++)
			{
				if (k == box[i][j] / 10)
				{
					A[num] = box[i][j];
					num++;
				}
			}


	/*for (int i = 0; i < 10; i++)
		for (int j = 0; j < flag[i]; j++)
			cout << box[i][j] << " ";*/

	
}


int main()
{
	void printresult();

	int *ori, *temp;
	ori = new int[N];//存放在堆上
	srand((unsigned)time(NULL)); //用当前系统时间设置种子


								 //平均情况
	for (int i = 0; i < N; i++)
	{
		int k = rand() % (N + 1);
		ori[i] = k;

	}
	for (int i = 0; i < N; i++)
		cout << ori[i] << " ";
	start = clock();
	radixsort<int>(ori);
	finish = clock();
	cout << "平均情况下:" << endl;
	printresult();
	cout << endl;

	for (int i = 0; i < N; i++)
		cout << ori[i] << " ";
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
