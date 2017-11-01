#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>
#include<time.h>
#include<stdio.h>
#include<stdlib.h>

using namespace std;
#define N 100000000


template <typename E>
void mergesort(E A[], E temp[], int left, int right) {
	if (left == right) return; // List of one element
	int mid = (left + right) / 2;
	mergesort<E>(A, temp, left, mid);
	mergesort<E>(A, temp, mid + 1, right);
	for (int i = left; i <= right; i++) // Copy subarray to temp
		temp[i] = A[i];
	// Do the merge operation back to A
	int i1 = left; int i2 = mid + 1;
	for (int curr = left; curr <= right; curr++) {
		if (i1 == mid + 1) // Left sublist exhausted
			A[curr] = temp[i2++];
		else if (i2 > right) // Right sublist exhausted
			A[curr] = temp[i1++];
		else if ((temp[i1]>temp[i2]))
			A[curr] = temp[i1++];
		else A[curr] = temp[i2++];
	}
}
int main()
{
	int *ori,*temp;
	
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
	
	mergesort<int>(ori, temp, 0, N);


	finish = clock();
	totaltime = (double)(finish - start) / CLOCKS_PER_SEC;
	cout << "\n此程序的运行时间为" << totaltime << "秒！" << endl;
	cout << endl;

	return 0;
}