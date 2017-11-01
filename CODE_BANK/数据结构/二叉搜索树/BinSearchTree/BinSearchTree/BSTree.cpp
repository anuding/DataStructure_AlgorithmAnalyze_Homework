#include "BSTree.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>
#include<time.h>
#include<stdio.h>
#include<stdlib.h>


using namespace std;
int main()
{
	BSTree<int, int*> tree;
	int n = 11;
	srand((unsigned)time(NULL)); //用当前系统时间设置种子
	

  cout << "Size: " << tree.size() << "\n";  
  tree.insert(15, new int(15));
  for (int j = 0; j < n-1; j++)
  {
	  int k = rand() % (n + 1);
	  tree.insert(k, new int(k));
  }
  
  tree.print();
  cout << "Size: " << tree.size() << "\n";  
 //tree.remove(15);
 // tree.print();  
 // cout << "Size: " << tree.size() << "\n";  
 //

  cout<<"Sum = "<<tree.Sum(tree.root,0);

	return 0;
}


int num[3];
void sort() { // Assume A has 3 elements
	if (num[0] < num[2] < num[1])
		swap(num[1], num[2]);
	if (num[1] < num[0] < num[2])
		swap(num[1], num[0]);
	if (num[1] < num[2] < num[0])
	{
		swap(num[1], num[0]);
		swap(num[1], num[2]);
	}
	if (num[2] < num[1] < num[0])
		swap(num[0], num[2]);
	if (num[2] < num[0] < num[1])
	{
		swap(num[2], num[0]);
		swap(num[1], num[2]);
	}
}
int num[3];
void sort() { 
	if (num[1] < num[0])
		if (num[2] < num[0])
			if (num[2] < num[1]) 
				swap(num[0], num[2]);
			else { 
				swap(num[0], num[1]);
				swap(num[1], num[2]);
			}
		else 
			swap(num[0], num[1]);
	else
		if (num[2] < num[1])
			if (num[2] < num[1]) { 
				swap(num[0], num[2]);
				swap(num[1], num[2]);
			}
			else 
				swap(num[1], num[2]);
		else
}



LList<int> mergesort(LList<int> inlist) {
	LList<int> templist[2];
	if (inlist.length() <= 1) return inlist;
	inlist.setStart();
	int curr = 0;
	
	while (!inlist.isEmpty()) {
		int item;
		inlist.remove(item);
		templist[curr].append(item);
		curr = (curr + 1) % 2;
	}
	mergesort(templist[0]);
	mergesort(templist[1]);
	
	templist[0].setFirst();
	templist[1].setFirst();
	while (!templist[0].isEmpty() ||
		!templist[1].isEmpty()) {
		if (templist[0].isEmpty()) {
			templist[1].remove(item);
			inlist.append(item);
		}
		else if (templist[1].isEmpty()) {
			templist[0].remove(item);
			inlist.append(item);
		}
		else if (templist[0].currValue() <
			templist[1].currValue()) {
			item = templist[0].remove();
			inlist.append(item);
		}
		else {
			item = templist[1].remove();
			inlist.append(item);
		}
	}
	return inlist;
}

template <typename E, typename Comp>
void mergesort(E A[], E temp[], int left, int right) {
	if (left == right) return; // List of one element
	int mid = (left + right) / 2;
	mergesort<E, Comp>(A, temp, left, mid);
	mergesort<E, Comp>(A, temp, mid + 1, right);
	for (int i = left; i <= right; i++) // Copy subarray to temp
		temp[i] = A[i];
	// Do the merge operation back to A
	int i1 = left; int i2 = mid + 1;
	for (int curr = left; curr <= right; curr++) {
		if (i1 == mid + 1) // Left sublist exhausted
			A[curr] = temp[i2++];
		else if (i2 > right) // Right sublist exhausted
			A[curr] = temp[i1++];
		else if (Comp::prior(temp[i1], temp[i2]))
			A[curr] = temp[i1++];
		else A[curr] = temp[i2++];
	}
}

