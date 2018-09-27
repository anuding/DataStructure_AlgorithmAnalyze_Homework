// Heap class
#include <assert.h>
template <typename E, typename Comp> class heap {
private:
	E* Heap; 
	int maxsize; //堆所能容纳的最大元素数
	int n; // 堆中目前的元素数量
		   
	void siftdown(int pos) {// 调整堆
		while (!isLeaf(pos)) { 
			int j = leftchild(pos); int rc = rightchild(pos);
			if ((comparetimes++)&&(rc < n) && (Heap[rc]> Heap[j]))
				j = rc; 
			if ((comparetimes++) && Heap[pos]> Heap[j]) return; 
			swap(Heap[pos], Heap[j]);
			swaptimes++;
			pos = j;
		}
	}
public:
	heap(E* h, int num, int max) // Constructor
	{
		Heap = h; n = num; maxsize = max; buildHeap();
	}
	int size() const // Return current heap size
	{
		return n;
	}
	bool isLeaf(int pos) const // True if pos is a leaf
	{
		return (pos >= n / 2) && (pos < n);
	}
	int leftchild(int pos) const
	{
		return 2 * pos + 1;
	} // Return leftchild position
	int rightchild(int pos) const
	{
		return 2 * pos + 2;
	} // Return rightchild position
	int parent(int pos) const // Return parent position
	{
		return (pos - 1) / 2;
	}
	void buildHeap() // Heapify contents of Heap
	{
		for (int i = n / 2 - 1; i >= 0; i--) siftdown(i);
	}
	// Insert "it" into the heap
	void insert(const E& it) {
		assert(n < maxsize, "Heap is full");
		int curr = n++;
		Heap[curr] = it; // Start at end of heap
						 // Now sift up until curr’s parent > curr
		while ((curr != 0) &&
			((Heap[curr]>Heap[parent(curr)]))) {
			swap(Heap[curr], Heap[parent(curr)]);
			curr = parent(curr);
		}
	}

	// Remove first value
	E removefirst() {
		assert(n > 0, "Heap is empty");
		swap(Heap[0], Heap[--n]); //根节点与最后的节点交换
		swaptimes++;
		if (n != 0) siftdown(0); // 删除后要调整堆
		return Heap[n]; // 返回原先根节点的值
	}
	// Remove and return element at specified position
	E remove(int pos) {
		assert((pos >= 0) && (pos < n), "Bad position");
		if (pos == (n - 1)) n--; // Last element, no work to do
		else
		{
			swap(Heap[pos], Heap[--n]); // Swap with last value
			while ((pos != 0) &&
				((Heap[pos]> Heap[parent(pos)]))) {
				swap(Heap[pos], Heap[parent(pos)]); // Push up large key
				pos = parent(pos);
			}
			if (n != 0) siftdown(pos); // Push down small key
		}
		return Heap[n];
	}
};