// 内部排序.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>
#include<time.h>
#include<stdio.h>
#include<stdlib.h>
static long long int swaptimes = 0;
static long long int comparetimes = 0;
static double totaltime;
static clock_t start, finish;
using namespace std;
#define N 20


template<typename E>
void insertsort(E A[], int n)//插入排序,传入待排序序列和序列的大小
{
	for (int i = 0; i<N; i++)
		for (int j = 0; j < i; j++)
		{
			if (A[j]<A[i])
			{
				swap(A[j], A[i]);
			}
		}
}



template<typename E>
void bubsort(E A[], int n)//冒泡排序,传入待排序序列和序列的大小
{
	for (int i = 0; i < N; i++)
	{
		for (int j = N-1; j >i; j--)
		{
			if (A[j] < A[j - 1])
				swap(A[j], A[j - 1]);
		}
	}
}


template<typename E>
void selsort(E A[], int n)//选择排序,传入待排序序列和序列的大小
{
	for (int i = 0; i < N; i++)
	{
		int lowindex = i;
		for (int j = N - 1; j >i; j--)
		{
			if (A[j] < A[lowindex])
				lowindex = j ;;
		}
		swap(A[i], A[lowindex]);
	}
}
int main()
{
	
	int *ori, *temp;
	ori = new int[N];//存放在堆上
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


	selsort(ori, N);

	for (int i = 0; i < N; i++)
	{
		cout << ori[i] << " ";
	}

	getchar();
    return 0;
}
