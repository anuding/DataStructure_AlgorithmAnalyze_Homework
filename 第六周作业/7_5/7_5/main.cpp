#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>
#include<time.h>
#include<stdio.h>
#include<stdlib.h>
using namespace std;



void selsort(int A[], int n) { // Selection Sort
	for (int i = 0; i<n - 1; i++) { // Select i’th record
		int lowindex = i; // Remember its index
		for (int j = n - 1; j>i; j--) // Find least value
			if ((A[j]< A[lowindex]))
				lowindex = j; // Put it in place
		//if (i != lowindex) // Add check for exercise
		{
			int temp;
			temp = A[i];
			A[i] = A[lowindex];
			A[lowindex] = temp;
		}

	}
}
int main()
{
	clock_t start, finish;
	double totaltime;
	start = clock();

	int  i = 0, n = 100000;
	static int TE00[100000];

	srand((unsigned)time(NULL)); //用当前系统时间设置种子
	int k = rand() % (n + 1);
	for (i = 0; i<n; i++)
		TE00[i] = i;

	/*for (int j = 0; j < 5; j++)
		cout << TE00[j]<<" ";*/
	//cout << endl;
	selsort(TE00, 100000);
	/*for (int j = 0; j < 5; j++)
		cout << TE00[j] << " ";*/

	finish = clock();
	totaltime = (double)(finish - start) / CLOCKS_PER_SEC;
	cout << "\n此程序的运行时间为" << totaltime << "秒！" << endl;
	return 0;
}