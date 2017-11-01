
/*
* -----------------------------------------------------------
*  Copyright (c) 2017 anuding.github.io All rights reserved.
* -----------------------------------------------------------
*
*        �����ߣ�  anuding
*      ����ʱ�䣺  2017/10/30 10:43:42
*          CLR��  4.0.30319.42000
*
*/


#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>
#include<time.h>
#include<stdio.h>
#include<stdlib.h>

using namespace std;
//#define N 100000000
#define N 50

template <typename E>
void selsort(E A[], int n) { // Selection Sort
	for (int i = 0; i<n - 1; i++) { // Select i��th record
		int lowindex = i; // Remember its index
		for (int j = n - 1; j>i; j--) // Find the least value
			if (A[j]> A[lowindex])
				lowindex = j; // Put it in place
		swap(A[i], A[lowindex]);
	}

}int main()
{
	int *ori, *temp;

	ori = new int[N];//����ڶ���
	//temp = new int[N];


	srand((unsigned)time(NULL)); //�õ�ǰϵͳʱ����������

	for (int i = 0; i < N; i++)
	{
		int k = rand() % (N + 1);
		ori[i] = k;
	}


	for (int i = 0; i < N; i++)
	{
		cout << ori[i] << " ";
	}
	clock_t start, finish;
	double totaltime;
	start = clock();

	//mergesort<int>(ori, temp, 0, N);
	selsort<int>(ori, N);

	finish = clock();
	totaltime = (double)(finish - start) / CLOCKS_PER_SEC;
	cout << "\n�˳��������ʱ��Ϊ" << totaltime << "�룡" << endl;
	cout << endl;


	for (int i = 0; i < N; i++)
	{
		cout << ori[i] << " ";
	}
	return 0;
}