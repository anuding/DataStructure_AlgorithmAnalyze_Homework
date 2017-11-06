
/*
* -----------------------------------------------------------
*  Copyright (c) 2017 anuding.github.io All rights reserved.
* -----------------------------------------------------------
*
*        �����ߣ�  anuding
*      ����ʱ�䣺  11/6/2017 8:20:33 AM
*          CLR��  4.0.30319.42000
*
*/

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
	ori = new int[N];//����ڶ���
	srand((unsigned)time(NULL)); //�õ�ǰϵͳʱ����������


								 //ƽ�����
	for (int i = 0; i < N; i++)
	{
		int k = rand() % (N + 1);
		ori[i] = k;

	}
	start = clock();
	findK(ori, N, rand() % (N + 1));
	finish = clock();
	cout << "ƽ�������:" << endl;
	printresult();
	cout << endl;




	//������
	for (int i = 0; i < N; i++)
		ori[i] = i;
	start = clock();
	findK(ori, N, 0);
	finish = clock();
	cout << "��������:" << endl;
	printresult();
	cout << endl;



	//������
	for (int i = 0; i < N; i++)
		ori[i] = i;
	start = clock();
	findK(ori, N, N-1);
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