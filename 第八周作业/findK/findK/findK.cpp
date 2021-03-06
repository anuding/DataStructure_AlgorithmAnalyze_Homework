#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>
#include<time.h>
#include<stdio.h>
#include<stdlib.h>

using namespace std;
//#define N 100000000
#define N 100

template <typename E>
int findK(E A[], int i, int j, E K)
{
	if (j <= i)
		return i; // Don’t sort 0 or 1 Elem
	int pivotindex = findpivot(A, i, j);
	swap(A[pivotindex], A[j]); // Put pivot at end
							   // k will be the first position in the right subarray
	int k = partition<E>(A, i - 1, j, A[j]);
	swap(A[k], A[j]); // Put pivot in place
	if (A[k] == K)
		return k;
	if (A[k] >= K)
		return findK<E>(A, i, k - 1, K);
	else 
		return findK<E>(A, k + 1, j, K);
}
template <typename E>
inline int findpivot(E A[], int i, int j)
{
	return (i + j) / 2;
}

template <typename E>
inline int partition(E A[], int l, int r, E& pivot) {
	do { // Move the bounds inward until they meet
		while ((A[++l]>pivot)); // Move l right and
		while ((l < r) && (pivot>A[--r])); // r left
		swap(A[l], A[r]); // Swap out-of-place values
	} while (l < r); // Stop when they cross
	return l; // Return first position in right partition
}


int main()
{
	int *ori, *temp;

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

	//mergesort<int>(ori, temp, 0, N);
	cout<<findK<int>(ori, 0, N,2);

	finish = clock();
	totaltime = (double)(finish - start) / CLOCKS_PER_SEC;
	cout << "\n此程序的运行时间为" << totaltime << "秒！" << endl;
	cout << endl;


	//for (int i = 0; i < N; i++)
	//{
	//	cout<<ori[i]<<" ";
	//}
	return 0;
}

//计数H G E D C A B F;比较总数53次
//移至前端 G H E C D A B F; 比较总数59次
//转置 A B D E H G C F; 比较总数95次