#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>
#include<time.h>
#include<stdio.h>
#include<stdlib.h>
#include<iomanip>
using namespace std;


void bubble_sort(int a[], int n);
void selection_sort(int a[], int n);

void main() {
	srand((unsigned)time(NULL)); //用当前系统时间设置种子
	static int a[1000000];
	int n = 1000000,i=0;
	for (i = 0; i<n; i++) 
		a[i] = rand() % (n+1);    //用rand函数生成0-1000000的随机数，并赋值给数组a[i]
	i = 0;


	clock_t start, finish;
	double totaltime;
	start = clock();

	//bubble_sort(a, n);
	selection_sort(a, n);

	finish = clock();
	totaltime = (double)(finish - start) / CLOCKS_PER_SEC;
	cout << "\n此程序的运行时间为" << totaltime << "秒！" << endl;

	/*for (i = 0; i < n; i++)
	{
		printf("%d  ", a[i]);
	}
	printf("\n");*/
	
	getchar();
}




void bubble_sort(int a[], int n)
{
	int i, j, temp;
	for (j = 0; j < n - 1; j++)
		for (i = 0; i < n - 1 - j; i++)
		{
			if (a[i] > a[i + 1])
			{
				temp = a[i];
				a[i] = a[i + 1];
				a[i + 1] = temp;
			}
		}
}

void selection_sort(int a[], int n)
{
	int i = 0, N = n,temp,j,b;
	
	for (i = 0; i<N - 1; i++)
	{
		temp = i;
		for (j = i + 1; j<N; j++)
		{
			if (a[temp]>a[j])
				temp = j;
		}
		if (i != temp)
		{
			b = a[temp];
			a[temp] = a[i];
			a[i] = b;
		}
	}
	/*for (i = 0; i<N; i++)
		cout  << a[i]<<"  ";
	cout << endl;*/
}