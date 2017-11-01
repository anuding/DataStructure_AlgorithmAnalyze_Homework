#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>
#include<time.h>
#include<stdio.h>
#include<stdlib.h>
#include "maxheap.h"
using namespace std;
//#define N 100000000
#define N 10000000

template <typename E>
void heapsort(E A[], int n) { // Heapsort
	E maxval;
	heap<E, int> H(A, n, n); // Build the heap
	for (int i = 0; i<n; i++) // Now sort
		maxval = H.removefirst(); // Place maxval at end
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

	clock_t start, finish;
	double totaltime;
	start = clock();

	//mergesort<int>(ori, temp, 0, N);
	heapsort<int>(ori,N);

	finish = clock();
	totaltime = (double)(finish - start) / CLOCKS_PER_SEC;
	cout << "\n此程序的运行时间为" << totaltime << "秒！" << endl;
	cout << endl;


	//for (int i = 0; i < N; i++)
	//{
	//	cout<<ori[i]<<" ";
	//}
	return 0;
}