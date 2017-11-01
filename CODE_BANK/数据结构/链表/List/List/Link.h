#include<iostream>
#include<iostream>
#include<stdlib.h>
#include<string>
#include<assert.h>
using namespace std;

template <typename E> class Link
{
public:
	E element;
	Link *next;

	Link (const E& elemval,Link* nextval=NULL)
	{element = elemval; next = nextval; }
	Link(Link* nextval = NULL)
	{
		next = nextval;
	}
};