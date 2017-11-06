
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
#define N 1000000
static long long int swaptimes = 0;
static long long int comparetimes = 0;
static double totaltime;
static clock_t start, finish;

using namespace std;

template <typename E>
void radixsort11(E A[]) 
{
	int box[10][N];//box用来存储每种余数的数据，box[4][0]表示余数为4的第一个数据
	int flag[10] = {0};//flag表示每种余数的数据总量，flag[4]==5表示共有5个余数为4的数据
	int bit = 10;
	while (bit * 10 != N)
	{
		for (int k = 0; k<10; k++)
			flag[k] = 0;
		for (int i = 0; i<N; i++)
		{
			int temp = A[i] /(bit/10)% bit;
			box[temp][flag[temp]] = A[i];
			flag[temp]++;
		}

		int num = 0;
		for (int k = 0; k<bit; k++)
			for (int i = 0; i < bit; i++)
				for (int j = 0; j < flag[i]; j++)
				{
					if (k == box[i][j] / 10)
					{
						A[num] = box[i][j];
						num++;
					}
				}
		bit = bit * 10;

	}
}

int maxbit(int data[], int n) //辅助函数，求数据的最大位数
{
	int d = 1; //保存最大的位数
	int p = 10;
	for (int i = 0; i < n; ++i)
	{
		while (data[i] >= p)
		{
			p *= 10;
			++d;
		}
	}
	return d;
}
void radixsort(int data[], int n) //基数排序
{
	int d = maxbit(data, n);
	int *tmp = new int[n];
	int *count = new int[10]; //计数器
	int i, j, k;
	int radix = 1;
	for (i = 1; i <= d; i++) //进行d次排序
	{
		for (j = 0; j < 10; j++)
			count[j] = 0; //每次分配前清空计数器
		for (j = 0; j < n; j++)
		{
			k = (data[j] / radix) % 10; //统计每个桶中的记录数
			count[k]++;
		}
		for (j = 1; j < 10; j++)
			count[j] = count[j - 1] + count[j]; //将tmp中的位置依次分配给每个桶
		for (j = n - 1; j >= 0; j--) //将所有桶中记录依次收集到tmp中
		{
			k = (data[j] / radix) % 10;
			tmp[count[k] - 1] = data[j];
			count[k]--;
		}
		for (j = 0; j < n; j++) //将临时数组的内容复制到data中
			data[j] = tmp[j];
		radix = radix * 10;
	}
	delete[]tmp;
	delete[]count;
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
	radixsort(ori, N);
	finish = clock();
	cout << "平均情况下:" << endl;
	printresult();
	cout << endl;




	//最好情况
	for (int i = 0, k = N; i < N; i++, k--)
		ori[i] = k;
	start = clock();
	radixsort(ori, N);
	finish = clock();
	cout << "最好情况下:" << endl;
	printresult();





	//最差情况
	for (int i = 0; i < N; i++)
		ori[i] = i;
	start = clock();
	radixsort(ori, N);
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
