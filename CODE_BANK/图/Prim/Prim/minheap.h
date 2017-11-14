#include <assert.h>
template <typename E, typename Comp> class heap
{  
	private:  
	  E* Heap;            
	  int maxsize;        
	  int n;              
	  
	    
	  void siftdown(int pos) {  
	    while (!isLeaf(pos)) {   
	      int j = leftchild(pos);  int rc = rightchild(pos);  
	      if ((rc < n) && (Heap[j]>Heap[rc]))  
	        j = rc;            
	      if ((Heap[j]>Heap[pos] )) return;   
	      swap(Heap[pos], Heap[j]);
	      pos = j;              
	    }  
	  }  
	  
	public:  
	  heap(E* h, int num, int max)       
	    { Heap = h;  n = num;  maxsize = max;  buildHeap(); }  
	  int size() const        
	    { return n; }  
	  bool isLeaf(int pos) const   
	    { return (pos >= n/2) && (pos < n); }  
	  int leftchild(int pos) const  
	    { return 2*pos + 1; }     
	  int rightchild(int pos) const  
	    { return 2*pos + 2; }     
	  int parent(int pos) const    
	    { return (pos-1)/2; }  
	  void buildHeap()             
	    { for (int i=n/2-1; i>=0; i--) siftdown(i); }  
	  
	  void insert(const E& it) {  
	    assert(n < maxsize, "Heap is full");  
	    int curr = n++;  
	    Heap[curr] = it;             
	    while ((curr!=0) &&  
	           ((Heap[parent(curr)]> Heap[curr]))) {  
	      swap(Heap[curr], Heap[parent(curr)]);
	      curr = parent(curr);  
	    }  
	  }  
	  E removefirst() {  
	    assert (n > 0, "Heap is empty");  
	    swap(Heap[0], Heap[--n]);
	    if (n != 0) siftdown(0);    
	    return Heap[n];             
	  }  
	  
	  E remove(int pos) {  
	    assert((pos >= 0) && (pos < n), "Bad position");  
	    if (pos == (n-1)) n--;   
	    else  
	    {  
	      swap(Heap[pos], Heap[--n]);
	      while ((pos != 0) &&  
	             ((Heap[parent(pos)]>Heap[pos]))) {  
	        swap(Heap[pos], Heap[parent(pos)]);
	        pos = parent(pos);  
	      }  
	      if (n != 0) siftdown(pos);       
	    }  
	    return Heap[n];  
	  }  
};

