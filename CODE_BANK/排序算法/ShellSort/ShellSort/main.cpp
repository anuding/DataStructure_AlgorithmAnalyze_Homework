
/*
* -----------------------------------------------------------
*  Copyright (c) 2017 anuding.github.io All rights reserved.
* -----------------------------------------------------------
*
*        创建者：  anuding
*      创建时间：  2017/10/31 15:55:43
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


//子序列中进行的插入排序
template <typename E>
void inssort2(E A[], int n, int incr) 
{
	for (int i = incr; i<n; i += incr)
		for (int j = i; (comparetimes++)&&(j >= incr) &&((A[j] > A[j - incr])); j -= incr)
		{
			swap(A[j], A[j - incr]);
			swaptimes++;
		}
}
template <typename E>
void shellsort(E A[], int n) {//传入待排序序列和序列的大小
	for (int i = n / 2; i>2; i /= 2) // 算增量,越算越小
		for (int j = 0; j<i; j++) 
			inssort2<E>(&A[j],  n-j, i);// 对第n-j个子序列(增量为i)进行插入排序
	inssort2<E>(A, n, 1); //增量为1即为直接插入排序
}


int main()
{
	void printresult();

	int *ori, *temp;
	ori = new int[N];//存放在堆上
	srand((unsigned)time(NULL)); //用当前系统时间设置种子						 
	for (int i = 0; i < N; i++)//平均情况
	{
		int k = rand() % (N + 1);
		ori[i] = k;
	}



	start = clock();
	shellsort<int>(ori, N);
	finish = clock();
	cout << "平均情况下:" << endl;
	printresult();
	cout << endl;


	//最好情况
	for (int i = 0, k =N; i < N; i++, k--)
		ori[i] = k;
	start = clock();
	shellsort<int>(ori, N);
	finish = clock();
	cout << "最好情况下:" << endl;
	printresult();


	//最差情况
	for (int i = 0; i < N; i++)
		ori[i] = i;
	start = clock();
	shellsort<int>(ori, N);
	finish = clock();
	cout << "最差情况下:" << endl;
	printresult();
	cout << endl;

	//for (int i = 0; i < N; i++)
	//	cout << ori[i] << " ";


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