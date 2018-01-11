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


template <typename E>
void qsort(E A[], int i, int j) { // Quicksort
	if (j <= i) return; // Don’t sort 0 or 1 element
	int pivotindex = findpivot(A, i, j);
	swap(A[pivotindex], A[j]); // Put pivot at end
	swaptimes++;
							// k will be the first position in the right subarray
	int k = partition<E>(A, i - 1, j, A[j]);
	swap(A[k], A[j]); // Put pivot in place
	swaptimes++;
	qsort<E>(A, i, k - 1);
	qsort<E>(A, k + 1, j);
}



template <typename E>
inline int findpivot(E A[], int i, int j)
{
	return (i + j) / 2;
}

template <typename E>
inline int partition(E A[], int l, int r, E& pivot) {
	do { // Move the bounds inward until they meet
		while ((A[++l]>pivot)&&(comparetimes++)); // Move l right and
		while ((comparetimes++)&&(l < r) && (pivot>A[--r])); // r left
		{
			swap(A[l], A[r]); // Swap out-of-place values
			swaptimes++;
		}

	} while (l < r); // Stop when they cross
	return l; // Return first position in right partition
}


int main()
{
	void printresult();

	int *ori, *temp;
	ori = new int[N];//存放在堆上
	srand((unsigned)time(NULL)); //用当前系统时间设置种子


								 //平均情况
	for (int i = 0; i < N; i++)
	{
		int k = rand() % (N + 1);
		ori[i] = k;

	}
	start = clock();
	qsort<int>(ori,0, N);
	finish = clock();
	cout << "平均情况下:" << endl;
	printresult();
	cout << endl;




	//最好情况
	for (int i = 0, k = N; i < N; i++, k--)
		ori[i] = k;
	start = clock();
	qsort<int>(ori, 0, N);
	finish = clock();
	cout << "最好情况下:" << endl;
	printresult();

	



	//最差情况
	for (int i = 0; i < N; i++)
		ori[i] = i;
	start = clock();
	qsort<int>(ori, 0, N);
	finish = clock();
	cout << "最差情况下:" << endl;
	printresult();
	cout << endl;
	getchar();
	return 0;
}

void printresult()
{
	totaltime = (double)(finish - start) / CLOCKS_PER_SEC;
	cout << "此程序的运行时间为" << totaltime << "秒！" << endl;
	cout << "共比较" << comparetimes << "次" << endl;
	cout << "共交换" << swaptimes << "次" << endl;
	swaptimes = 0;
	comparetimes = 0;
	cout << endl;
}