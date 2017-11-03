#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>
#include<time.h>
#include<stdio.h>
#include<stdlib.h>
#include "maxheap.h"
#define N 50
static long long int swaptimes = 0;
static long long int comparetimes = 0;
static double totaltime;
static clock_t start, finish;

using namespace std;

template <typename E>
void heapsort(E A[], int n) { // Heapsort
	E maxval;
	heap<E, int> H(A, n, n); // Build the heap
	for (int i = 0; i<n; i++) // Now sort
		maxval = H.removefirst(); // Place maxval at end
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
	start = clock();
	heapsort<int>(ori, N);
	finish = clock();
	cout << "平均情况下:" << endl;
	printresult();
	cout << endl;




	//最好情况
	for (int i = 0; i < N; i++)
		ori[i] = i;
	start = clock();
	heapsort<int>(ori, N);
	finish = clock();
	cout << "最好情况下:" << endl;
	printresult();
	cout << endl;






	//最差情况
	for (int i = 0, k = N; i < N; i++, k--)
		ori[i] = k;
	start = clock();
	heapsort<int>(ori, N);
	finish = clock();
	cout << "最差情况下:" << endl;
	printresult();
	//为什么最差的和最好的结果反了?
	for (int i = 0; i < N; i++)
		cout<<ori[i]<<" ";
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