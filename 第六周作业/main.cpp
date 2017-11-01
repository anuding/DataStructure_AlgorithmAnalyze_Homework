#include "Astack.h"
using namespace std;

int main()
{
	AStack<int> Input;    
	  Input.push(5);  
	  Input.push(1);  
	  Input.push(3);  
	  Input.push(4);  
	  Input.push(6);  
	  
	  Input.print();
	

	  AStack<int> a, b;
	  while (!Input.isEmpty())
		  a.push(Input.pop());
	  b.push(a.pop());
	  while (!a.isEmpty())
	  {
		  
		  while ((!b.isEmpty())&&(b.topValue() > a.topValue()))
			  Input.push(b.pop());
			b.push(a.pop());
	      while (!Input.isEmpty())
			  b.push(Input.pop());
	  }
	  while (!b.isEmpty())
		  Input.push(b.pop());
	    
		  Input.print();
    
	  return 0;  

}

