
/*
* -----------------------------------------------------------
*  Copyright (c) 2017 anuding.github.io All rights reserved.
* -----------------------------------------------------------
*
*        创建者：  anuding
*      创建时间：  11/6/2017 8:20:33 AM
*          CLR：  4.0.30319.42000
*
*/

/*
* -----------------------------------------------------------
*  Copyright (c) 2017 anuding.github.io All rights reserved.
* -----------------------------------------------------------
*
*        创建者：  anuding
*      创建时间：  2017/10/30 10:30:23
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
	int findK(int A[], int n, int K);
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
	findK(ori, N, rand() % (N + 1));
	finish = clock();
	cout << "平均情况下:" << endl;
	printresult();
	cout << endl;




	//最好情况
	for (int i = 0; i < N; i++)
		ori[i] = i;
	start = clock();
	findK(ori, N, 0);
	finish = clock();
	cout << "最好情况下:" << endl;
	printresult();
	cout << endl;



	//最差情况
	for (int i = 0; i < N; i++)
		ori[i] = i;
	start = clock();
	findK(ori, N, N-1);
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
int findK(int A[], int n,int K) 
{
	for (int i = 0; i<n; i++)
		if (abs(A[i]-K)<=0.00001)
		{
			comparetimes = i+1;
			return i; 
		}
	return -1;
}//