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
	LList() { init(); }        //��ʼ��
	~LList() {  }//removeall();
public:
	void removehead();
	void removetail();
	void print();                   //��ӡ����Ԫ��
	void clear() { removehead(); init(); } //���
	void insert(const E&it);          //curr����
	void append(const E&it);          //tail����
	 E remove();
	void moveToStart();
	void moveToEnd();
	void prev();
	void next();
	int length() const { return cnt };
	int currPos()const;
	void moveToPos(int pos);
	//void inversion(int size);              //���ú���
	void merge(LList a, LList b);
};

