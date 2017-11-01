#include "Link.h"
template<typename E>class LList
{
public:
	Link<E>* head;
	Link<E>* curr;
	Link<E>* tail;
	int cnt;


	void init()
	{
		curr = tail = head = new Link<E>;
		cnt = 0;
	}



public:
	LList() { init(); }        //初始化
	~LList() {  }//removeall();
public:
	void removehead();
	void removetail();
	void print();                   //打印链表元素
	void clear() { removehead(); init(); } //清除
	void insert(const E&it);          //curr插入
	void append(const E&it);          //tail插入
	 E remove();
	void moveToStart();
	void moveToEnd();
	void prev();
	void next();
	int length() const { return cnt };
	int currPos()const;
	void moveToPos(int pos);
	//void inversion(int size);              //倒置函数
	void merge(LList a, LList b);
};

