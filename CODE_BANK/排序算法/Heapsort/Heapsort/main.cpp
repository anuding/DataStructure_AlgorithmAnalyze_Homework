#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>
#include<time.h>
#include<stdio.h>
#include<stdlib.h>
#include "maxheap.h"
#define N 10000
static long long int swaptimes = 0;
static long long int comparetimes = 0;
static double totaltime;
static clock_t start, finish;

using namespace std;

template <typename E>
void heapsort(E A[], int n) { //传入待排序序列和序列的大小
	E maxval;
	heap<E, int> H(A, n, n); // 建堆
	for (int i = 0; i<n; i++) // 排序
		maxval = H.removefirst();
}

int main()
{
	void printresult();

	int *ori, *temp;
	ori = new int[N];//存放在堆上
	srand((unsigned)time(NULL)); //用当前系统时间设置种子
								
	for (int i = 0; i < N; i++) //平均情况
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
	for (int i = 0, k = N; i < N; i++, k--)
		ori[i] = k;
	start = clock();
	heapsort<int>(ori, N);
	finish = clock();
	cout << "最好情况下:" << endl;
	printresult();
	cout << endl;


	//最差情况
	for (int i = 0; i < N; i++)
		ori[i] = i;
	start = clock();
	heapsort<int>(ori, N);
	finish = clock();
	cout << "最差情况下:" << endl;
	printresult();
	
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