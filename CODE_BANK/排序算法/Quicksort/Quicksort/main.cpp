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
//void qsort(E A[], int i, int j) { //传入待排序序列和左端,右端
//	if (j <= i) return; 
//	int pivotindex = findpivot(A, i, j);//定义轴值
//	swap(A[pivotindex], A[j]); // 轴值置尾
//	swaptimes++;
//						
//	int k = partition<E>(A, i - 1, j, A[j]);//进行划分,顺便求得右子数组的左端,左子数组的右端
//	swap(A[k], A[j]); // 轴值置尾
//	swaptimes++;
//	qsort<E>(A, i, k - 1);//左子数组进行快排
//	qsort<E>(A, k + 1, j);//右子数组进行快排
//}
//
//
//
//template <typename E>
//inline int findpivot(E A[], int i, int j)//输入左端右端定义轴值
//{
//	return (i + j) / 2;
//}
//
//template <typename E>
//inline int partition(E A[], int l, int r, E& pivot) {
//	do { 
//		while ((A[++l]>pivot)&&(comparetimes++)); //左端右移 右端左移
//		while ((comparetimes++)&&(l < r) && (pivot>A[--r])); 
//		{
//			swap(A[l], A[r]); //在满足轴值左小右大的情况下交换
//			swaptimes++;
//		}
//
//	} while (l < r);
//	return l; // 返回右子数组的左端
//}





int findpivot(int A[], int i, int j)//输入左端右端定义轴值
{
	return (i + j) / 2;
}


int partition(int A[], int l, int r, int  pivot) {
	do {
		while (A[++l]>pivot); //左端右移 右端左移
		while ((l < r) && (pivot>A[--r]));
		{
			//swap(A[l], A[r]); //在满足轴值左小右大的情况下交换
			int tmp;
			tmp = A[l];
			A[l] = A[r];
			A[r] = tmp;

		}

	} while (l < r);
	return l; // 返回右子数组的左端
}

void qsort(int A[], int i, int j) { //传入待排序序列和左端,右端
	if (j <= i) return; 
	int pivotindex = findpivot(A, i, j);//定义轴值
	//swap(A[pivotindex], A[j]); // 轴值置尾
	int tmp;
	tmp = A[pivotindex];
	A[pivotindex] = A[j];
	A[j] = tmp;
						
	int k = partition(A, i - 1, j, A[j]);//进行划分,顺便求得右子数组的左端,左子数组的右端
	//swap(A[k], A[j]); // 轴值置尾
	tmp = A[k];
	A[k] = A[j];
	A[j] = tmp;
	
	qsort(A, i, k - 1);//左子数组进行快排
	qsort(A, k + 1, j);//右子数组进行快排
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
		cout << ori[i] << " ";
	}
	start = clock();
	//qsort<int>(ori,0, N);
	qsort(ori, 0, N);
	finish = clock();
	cout << "平均情况下:" << endl;
	printresult();
	cout << endl;

	for (int i = 0; i < N; i++)
		cout << ori[i] << " ";


	////最好情况
	//for (int i = 0, k = N; i < N; i++, k--)
	//	ori[i] = k;
	//start = clock();
	//qsort<int>(ori, 0, N);
	//finish = clock();
	//cout << "最好情况下:" << endl;
	//printresult();

	//



	////最差情况
	//for (int i = 0; i < N; i++)
	//	ori[i] = i;
	//start = clock();
	//qsort<int>(ori, 0, N);
	//finish = clock();
	//cout << "最差情况下:" << endl;
	//printresult();
	//cout << endl;
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