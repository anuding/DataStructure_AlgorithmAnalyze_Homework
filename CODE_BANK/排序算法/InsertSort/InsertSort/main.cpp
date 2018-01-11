/*
* -----------------------------------------------------------
*  Copyright (c) 2017 anuding.github.io All rights reserved.
* -----------------------------------------------------------
*
*        �����ߣ�  anuding
*      ����ʱ�䣺  2017/10/30 10:30:23
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
//#define N 100000000
#define N 150
static long long int swaptimes=0;
static long long int comparetimes = 0;
static double totaltime;
static clock_t start, finish;

using namespace std;

template<typename E>
void insertsort(E A[], int n)
{
	for (int i = 1; i < n; i++)
		for (int j = i; (comparetimes++) && (j > 0) && (A[j] < A[j - 1]); j--)
		{
			swap(A[j], A[j - 1]);
			swaptimes++;
		}
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
	insertsort<int>(ori, N);
	finish = clock();
	cout << "ƽ�������:" << endl;
	printresult();
	cout << endl;

	


	//������
	for (int i = 0; i < N; i++)
		ori[i] = i;
	start = clock();
	insertsort<int>(ori, N);
	finish = clock();
	cout << "��������:" << endl;
	printresult();
	cout << endl;



	//������
	for (int i = 0,k=N; i < N; i++,k--)
		ori[i] = k;	
	start = clock();
	insertsort<int>(ori, N);
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


