#include"Link.h"

template<typename E>class LList{
public:
	Link<E>* head;
	Link<E>* curr;
	Link<E>* tail;
	int cnt;
	
	void init(){	
	    tail=new Link<E>(0,0);
		curr=head=new Link<E>(0,tail);
		head=new Link<E>(0,tail);
		tail=new Link<E>(head,0);
		curr=head;

		cnt=0;
	};
	void removehead();
	void removetail();

public:
	LList(int size){init();}        //��ʼ��
	~LList(){removehead();}          
	void print();                   //��ӡ����Ԫ��
	void clear(){removehead();init();} //���
	void insert(const E&it);          //curr����
	void append(const E&it);          //tail����
	void remove();
	void moveToStart();              
	void moveToEnd();
	void prev();
	void next();
	int length() const{return cnt};
	int currPos()const;
	void moveToPos(int pos);
    void inversion(int size);              //���ú���
	void merge(LList a, LList b);
};
