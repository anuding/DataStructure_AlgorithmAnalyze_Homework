
/*
* -----------------------------------------------------------
*  Copyright (c) 2017 anuding All rights reserved.
* -----------------------------------------------------------
*
*        �����ߣ�  anuding
*      ����ʱ�䣺  2017/10/23 19:22:57
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
#define N 10000
static long long int swaptimes = 0;
static long long int comparetimes = 0;
static double totaltime;
static clock_t start, finish;

using namespace std;

template <typename E>
void radixsort(E A[]) 
{
	int box[10][N];//box�����洢ÿ�����������ݣ�box[4][0]��ʾ����Ϊ4�ĵ�һ������
	int flag[10] = {0};//flag��ʾÿ������������������flag[4]==5��ʾ����5������Ϊ4������
	int bit = N / 10;
	for (int i = 0; i<N; i++)
	{
		int temp = A[i] % 10;
		box[temp][flag[temp]] = A[i];
		flag[temp]++;
	}
	
	int num=0;
	for(int k=0;k<10;k++)
		for (int i = 0; i < 10; i++)
			for (int j = 0; j < flag[i]; j++)
			{
				if (k == box[i][j] / 10)
				{
					A[num] = box[i][j];
					num++;
				}
			}


	/*for (int i = 0; i < 10; i++)
		for (int j = 0; j < flag[i]; j++)
			cout << box[i][j] << " ";*/

	
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
	for (int i = 0; i < N; i++)
		cout << ori[i] << " ";
	start = clock();
	radixsort<int>(ori);
	finish = clock();
	cout << "ƽ�������:" << endl;
	printresult();
	cout << endl;

	for (int i = 0; i < N; i++)
		cout << ori[i] << " ";
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
