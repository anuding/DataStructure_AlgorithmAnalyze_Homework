#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>
#include<time.h>
#include<stdio.h>
#include<stdlib.h>
#include "maxheap.h"
#define N 50
static long long int swaptimes = 0;
static long long int comparetimes = 0;
static double totaltime;
static clock_t start, finish;

using namespace std;

template <typename E>
void heapsort(E A[], int n) { // Heapsort
	E maxval;
	heap<E, int> H(A, n, n); // Build the heap
	for (int i = 0; i<n; i++) // Now sort
		maxval = H.removefirst(); // Place maxval at end
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
	heapsort<int>(ori, N);
	finish = clock();
	cout << "ƽ�������:" << endl;
	printresult();
	cout << endl;




	//������
	for (int i = 0; i < N; i++)
		ori[i] = i;
	start = clock();
	heapsort<int>(ori, N);
	finish = clock();
	cout << "��������:" << endl;
	printresult();
	cout << endl;






	//������
	for (int i = 0, k = N; i < N; i++, k--)
		ori[i] = k;
	start = clock();
	heapsort<int>(ori, N);
	finish = clock();
	cout << "��������:" << endl;
	printresult();
	//Ϊʲô���ĺ���õĽ������?
	for (int i = 0; i < N; i++)
		cout<<ori[i]<<" ";
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