#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>
#include<time.h>
#include<stdio.h>
#include<stdlib.h>
#define N 20
#define NUMS 40
#define PI 3.14159
static long long int swaptimes = 0;
static long long int comparetimes = 0;
static double totaltime;
static clock_t start, finish;

using namespace std;


//template <typename E>
//void qsort(E A[], int i, int j) { //������������к����,�Ҷ�
//	if (j <= i) return; 
//	int pivotindex = findpivot(A, i, j);//������ֵ
//	swap(A[pivotindex], A[j]); // ��ֵ��β
//	swaptimes++;
//						
//	int k = partition<E>(A, i - 1, j, A[j]);//���л���,˳�����������������,����������Ҷ�
//	swap(A[k], A[j]); // ��ֵ��β
//	swaptimes++;
//	qsort<E>(A, i, k - 1);//����������п���
//	qsort<E>(A, k + 1, j);//����������п���
//}
//
//
//
//template <typename E>
//inline int findpivot(E A[], int i, int j)//��������Ҷ˶�����ֵ
//{
//	return (i + j) / 2;
//}
//
//template <typename E>
//inline int partition(E A[], int l, int r, E& pivot) {
//	do { 
//		while ((A[++l]>pivot)&&(comparetimes++)); //������� �Ҷ�����
//		while ((comparetimes++)&&(l < r) && (pivot>A[--r])); 
//		{
//			swap(A[l], A[r]); //��������ֵ��С�Ҵ������½���
//			swaptimes++;
//		}
//
//	} while (l < r);
//	return l; // ����������������
//}





int findpivot(int A[], int i, int j)//��������Ҷ˶�����ֵ
{
	return (i + j) / 2;
}


int partition(int A[], int l, int r, int  pivot) {
	do {
		while (A[++l]>pivot); //������� �Ҷ�����
		while ((l < r) && (pivot>A[--r]));
		{
			//swap(A[l], A[r]); //��������ֵ��С�Ҵ������½���
			int tmp;
			tmp = A[l];
			A[l] = A[r];
			A[r] = tmp;

		}

	} while (l < r);
	return l; // ����������������
}

void qsort(int A[], int i, int j) { //������������к����,�Ҷ�
	if (j <= i) return; 
	int pivotindex = findpivot(A, i, j);//������ֵ
	//swap(A[pivotindex], A[j]); // ��ֵ��β
	int tmp;
	tmp = A[pivotindex];
	A[pivotindex] = A[j];
	A[j] = tmp;
						
	int k = partition(A, i - 1, j, A[j]);//���л���,˳�����������������,����������Ҷ�
	//swap(A[k], A[j]); // ��ֵ��β
	tmp = A[k];
	A[k] = A[j];
	A[j] = tmp;
	
	qsort(A, i, k - 1);//����������п���
	qsort(A, k + 1, j);//����������п���
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
		cout << ori[i] << " ";
	}
	start = clock();
	//qsort<int>(ori,0, N);
	qsort(ori, 0, N);
	finish = clock();
	cout << "ƽ�������:" << endl;
	printresult();
	cout << endl;

	for (int i = 0; i < N; i++)
		cout << ori[i] << " ";


	////������
	//for (int i = 0, k = N; i < N; i++, k--)
	//	ori[i] = k;
	//start = clock();
	//qsort<int>(ori, 0, N);
	//finish = clock();
	//cout << "��������:" << endl;
	//printresult();

	//



	////������
	//for (int i = 0; i < N; i++)
	//	ori[i] = i;
	//start = clock();
	//qsort<int>(ori, 0, N);
	//finish = clock();
	//cout << "��������:" << endl;
	//printresult();
	//cout << endl;
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