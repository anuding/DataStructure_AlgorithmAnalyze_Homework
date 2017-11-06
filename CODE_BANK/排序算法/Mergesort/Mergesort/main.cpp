#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>
#include<time.h>
#include<stdio.h>
#include<stdlib.h>
#define N 100000
static long long int swaptimes = 0;
static long long int comparetimes = 0;
static double totaltime;
static clock_t start, finish;

using namespace std;

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
		else if ((comparetimes++)&&(temp[i1]>temp[i2]))
			A[curr] = temp[i1++];
		else A[curr] = temp[i2++];
	}
}


int main()
{
	void printresult();

	int *ori, *temp;
	ori = new int[N];//����ڶ���
	temp = new int[N];//����ڶ���
	srand((unsigned)time(NULL)); //�õ�ǰϵͳʱ����������


								 //ƽ�����
	for (int i = 0; i < N; i++)
	{
		int k = rand() % (N + 1);
		ori[i] = k;

	}
	start = clock();
	mergesort<int>(ori, temp, 0, N);
	finish = clock();
	cout << "ƽ�������:" << endl;
	printresult();
	cout << endl;
	delete temp;
	temp = new int[N];//����ڶ���




	//������
	for (int i = 0, k = N; i < N; i++, k--)
		ori[i] = k;
	start = clock();
	mergesort<int>(ori, temp, 0, N);
	finish = clock();
	cout << "��������:" << endl;
	printresult();
	delete temp;
	temp = new int[N];//����ڶ���




	//������
	for (int i = 0; i < N; i++)
		ori[i] = i;
	start = clock();
	mergesort<int>(ori, temp, 0, N);
	finish = clock();
	cout << "��������:" << endl;
	printresult();
	cout << endl;

	//for (int i = 0; i < N; i++)
	//	cout<<ori[i]<<" ";
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