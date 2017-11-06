
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
#define N 1000000
static long long int swaptimes = 0;
static long long int comparetimes = 0;
static double totaltime;
static clock_t start, finish;

using namespace std;

template <typename E>
void radixsort11(E A[]) 
{
	int box[10][N];//box�����洢ÿ�����������ݣ�box[4][0]��ʾ����Ϊ4�ĵ�һ������
	int flag[10] = {0};//flag��ʾÿ������������������flag[4]==5��ʾ����5������Ϊ4������
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

int maxbit(int data[], int n) //���������������ݵ����λ��
{
	int d = 1; //��������λ��
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
void radixsort(int data[], int n) //��������
{
	int d = maxbit(data, n);
	int *tmp = new int[n];
	int *count = new int[10]; //������
	int i, j, k;
	int radix = 1;
	for (i = 1; i <= d; i++) //����d������
	{
		for (j = 0; j < 10; j++)
			count[j] = 0; //ÿ�η���ǰ��ռ�����
		for (j = 0; j < n; j++)
		{
			k = (data[j] / radix) % 10; //ͳ��ÿ��Ͱ�еļ�¼��
			count[k]++;
		}
		for (j = 1; j < 10; j++)
			count[j] = count[j - 1] + count[j]; //��tmp�е�λ�����η����ÿ��Ͱ
		for (j = n - 1; j >= 0; j--) //������Ͱ�м�¼�����ռ���tmp��
		{
			k = (data[j] / radix) % 10;
			tmp[count[k] - 1] = data[j];
			count[k]--;
		}
		for (j = 0; j < n; j++) //����ʱ��������ݸ��Ƶ�data��
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
	ori = new int[N];//����ڶ���
	srand((unsigned)time(NULL)); //�õ�ǰϵͳʱ����������


								 //ƽ�����
	for (int i = 0; i < N; i++)
	{
		int k = rand() % (N + 1);
		ori[i] = k;

	}
	start = clock();
	radixsort(ori, N);
	finish = clock();
	cout << "ƽ�������:" << endl;
	printresult();
	cout << endl;




	//������
	for (int i = 0, k = N; i < N; i++, k--)
		ori[i] = k;
	start = clock();
	radixsort(ori, N);
	finish = clock();
	cout << "��������:" << endl;
	printresult();





	//������
	for (int i = 0; i < N; i++)
		ori[i] = i;
	start = clock();
	radixsort(ori, N);
	finish = clock();
	cout << "��������:" << endl;
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
	cout << "�˳��������ʱ��Ϊ" << totaltime << "�룡" << endl;
	cout << "���Ƚ�" << comparetimes << "��" << endl;
	cout << "������" << swaptimes << "��" << endl;
	swaptimes = 0;
	comparetimes = 0;
	cout << endl;
}
