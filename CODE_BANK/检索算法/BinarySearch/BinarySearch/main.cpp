
/*
* -----------------------------------------------------------
*  Copyright (c) 2017 anuding.github.io All rights reserved.
* -----------------------------------------------------------
*
*        创建者：  anuding
*      创建时间：  11/6/2017 8:49:58 AM
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
//#define N 100000000
#define N 100000
static long long int swaptimes = 0;
static long long int comparetimes = 0;
static double totaltime;
static clock_t start, finish;

using namespace std;





int main()
{
	void printresult();
	int binfindK(int A[], int n, int K);
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
	binfindK(ori, N, rand() % (N + 1));
	finish = clock();
	cout << "平均情况下:" << endl;
	printresult();
	cout << endl;




	//最好情况
	for (int i = 0; i < N; i++)
		ori[i] = i;
	start = clock();
	binfindK(ori, N,N/2-1);
	finish = clock();
	cout << "最好情况下:" << endl;
	printresult();
	cout << endl;



	//最差情况
	for (int i = 0; i < N; i++)
		ori[i] = i;
	start = clock();
	binfindK(ori, N, 1);
	finish = clock();
	cout << "最差情况下:" << endl;
	printresult();
	cout << endl;

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


// Return position of largest value in "A" of size "n"
int binfindK(int A[], int n, int K)
{
	int min = 0;
	int max = n- 1;
	int mid = (max + min) / 2;
	while (A[mid] != K) 
	{
		comparetimes++;
		if (K>A[mid]) {
			min = mid + 1;
		}
		else {
			max = mid - 1;
		}
		if (min>max)
			return -1;
		mid = (max + min) / 2;
	}
	comparetimes++;
	return mid;
}//