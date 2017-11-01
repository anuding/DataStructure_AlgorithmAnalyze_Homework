#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>
#include<time.h>
#include<stdio.h>
#include<stdlib.h>

using namespace std;


int SeqSearch(int a[], int n,int k);
int BinSearch(int array[], int n, int k);


int main()
{

	int  i = 0, n =  100000000;
	static int array[100000000];

	srand((unsigned)time(NULL)); //用当前系统时间设置种子
	int k = rand() % (n + 1);

	for (i = 0; i<n; i++)
		array[i] = i;

	clock_t start, finish;
	double totaltime;
	start = clock();

	SeqSearch(array,n,k);
	//BinSearch(array, n, k);

	finish = clock();
	totaltime = (double)(finish - start) / CLOCKS_PER_SEC;
	cout << "\n此程序的运行时间为" << totaltime << "秒！" << endl;
	getchar();
}


int SeqSearch(int array[], int n, int k)
{
	int  i = 0;

	for (i = 0; i<n; i++)
		if (array[i] == k)
			cout << "find k: " << k << " at " << i<<endl;
	return 0;
}

int BinSearch(int array[], int n, int k)
{
	
	int left = -1, right = n;
	while (left + 1 != right)
	{
		int  i = (left + right) / 2;
		if (k < array[i])
			right = i;
		if (k == array[i])
		{
			cout << "find k:" << k << " at " << i<<endl;
			return 0;
		}
		if (k > array[i])
			left = i;
	}
	return 0;
}

