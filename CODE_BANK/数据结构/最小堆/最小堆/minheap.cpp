#include <iostream>
#include "minheap.h"
using namespace std;
int main()
{
int test[10] = { 1,1,3,1,1 };
heap<int, int> heap(test, 10, 11);


heap.insert(2);
for (int i = 0; i <= 10; i++)
cout << test[i] << " ";
cout << "\n" << "insert finish" << "\n";

heap.remove(3);
for (int i = 0; i <= 9; i++)
cout << test[i] << " ";
cout << "\n" << "remove 3 finish" << "\n";

heap.removefirst();
for (int i = 0; i <= 8; i++)
cout << test[i] << " ";
cout << "\n" << "removefirst finish" << "\n";

return 0;
}