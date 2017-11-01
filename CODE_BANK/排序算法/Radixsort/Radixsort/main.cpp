
/*
* -----------------------------------------------------------
*  Copyright (c) 2014 anuding All rights reserved.
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
using namespace std;
#define N 25

template <typename E, typename getKey>
void radix(E A[], E B[],
	int n, int k, int r, int cnt[]) {
	// cnt[i] stores number of records in bin[i]
	int j;
	for (int i = 0, rtoi = 1; i<k; i++, rtoi *= r) { // For k digits
		for (j = 0; j<r; j++) cnt[j] = 0; // Initialize cnt
										  // Count the number of records for each bin on this pass
		for (j = 0; j<n; j++) cnt[(getKey::key(A[j]) / rtoi) % r]++;
		// Index B: cnt[j] will be index for last slot of bin j.
		for (j = 1; j<r; j++) cnt[j] = cnt[j - 1] + cnt[j];
		// Put records into bins, work from bottom of each bin.
		// Since bins fill from bottom, j counts downwards
		for (j = n - 1; j >= 0; j--)
			B[--cnt[(getKey::key(A[j]) / rtoi) % r]] = A[j];
		for (j = 0; j<n; j++) A[j] = B[j]; // Copy B back to A
	}
}


template <typename E>
void radixsort(E A[]) 
{
	int box[10][N];
	int flag[10] = {0};
	for (int i = 0; i<N; i++)
	{
		int temp = A[i] % 10;
		box[temp][flag[temp]] = A[i];
		flag[temp]++;
	}
	//flag[10] = { 0 };
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
	int *ori, *temp;
	ori = new int[N];//存放在堆上
	temp = new int[N];

	srand((unsigned)time(NULL)); //用当前系统时间设置种子

	for (int i = 0; i < N; i++)
	{
		int k = rand() % (N + 1);
		ori[i] = k;
	}
	for (int i = 0; i < N; i++)
	{
		cout << ori[i] << " ";
	}
	cout << endl;
	clock_t start, finish;
	double totaltime;
	start = clock();

	radixsort<int>(ori);

	finish = clock();
	totaltime = (double)(finish - start) / CLOCKS_PER_SEC;
	cout << "\n此程序的运行时间为" << totaltime << "秒！" << endl;
	cout << endl;
	
	for (int i = 0; i < N; i++)
	{
		cout<<ori[i]<<" ";
	}
    return 0;
}

