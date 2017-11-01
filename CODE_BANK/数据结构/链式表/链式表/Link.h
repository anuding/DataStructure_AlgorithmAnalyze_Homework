//#include<iostream>
//#include<iostream>
//#include<stdlib.h>
//#include<string>
//#include<assert.h>
//using namespace std;
//
//template <typename E>class Link {
//private:
//	static Link<E>* freelist;
//public:
//	E element;
//	Link<E>*next;
//	//Link<E>*prev;
//
//	Link(const E& it, Link* prevp, Link* nextp) {
//		element = it;
//		prev = prevp;
//		next = nextp;
//	}
//
//	Link(Link* prevp = NULL, Link* nextp = NULL) {
//		prev = prevp;
//		next = nextp;
//	}
//};
#include<string>
#include<assert.h>
using namespace std;

template <typename E>class Link {
private:
	static Link<E>* freelist;
public:
	E element;
	Link<E>*next;


	Link(const E& it, Link* nextp) {
		element = it;
		next = nextp;
	}
};
