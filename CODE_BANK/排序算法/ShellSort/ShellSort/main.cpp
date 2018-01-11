
/*
* -----------------------------------------------------------
*  Copyright (c) 2017 anuding.github.io All rights reserved.
* -----------------------------------------------------------
*
*        �����ߣ�  anuding
*      ����ʱ�䣺  2017/10/31 15:55:43
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
#define N 1000
static long long int swaptimes = 0;
static long long int comparetimes = 0;
static double totaltime;
static clock_t start, finish;

using namespace std;


// Modified version of Insertion Sort for varying increments
template <typename E>
void inssort2(E A[], int n, int incr) {
	for (int i = incr; i<n; i += incr)
		for (int j = i; (comparetimes++)&&(j >= incr) &&
			((A[j] > A[j - incr])); j -= incr)
		{
			swap(A[j], A[j - incr]);
			swaptimes++;
		}
}
template <typename E>
void shellsort(E A[], int n) { // Shellsort
	for (int i = n / 2; i>2; i /= 2) // For each increment
		for (int j = 0; j<i; j++) // Sort each sublist
			inssort2<E>(&A[j], n - j, i);
	inssort2<E>(A, n, 1);
}


int main()
{
	void printresult();

	int *ori, *temp;
	ori = new int[N];//����ڶ���
	srand((unsigned)time(NULL)); //�õ�ǰϵͳʱ����������


								 //ƽ�����
	for (int i = 0; i < N; i++)
	{
		int k = rand() % (N + 1);
		ori[i] = k;

	}
	start = clock();
	shellsort<int>(ori, N);
	finish = clock();
	cout << "ƽ�������:" << endl;
	printresult();
	cout << endl;




	//������
	for (int i = 0, k = N; i < N; i++, k--)
		ori[i] = k;
	start = clock();
	shellsort<int>(ori, N);
	finish = clock();
	cout << "��������:" << endl;
	printresult();





	//������
	for (int i = 0; i < N; i++)
		ori[i] = i;
	start = clock();
	shellsort<int>(ori, N);
	finish = clock();
	cout << "��������:" << endl;
	printresult();
	cout << endl;
	getchar();
	return 0;
}

void printresult()
{
	totaltime = (double)(finish - start) / CLOCKS_PER_SEC;
	cout << "�˳��������ʱ��Ϊ" << totaltime << "�룡" << endl;
	cout << "���Ƚ�" << comparetimes << "��" << endl;
	cout << "������" << swaptimes << "��" << endl;
	swaptimes = 0;
	comparetimes = 0;
	cout << endl;
}