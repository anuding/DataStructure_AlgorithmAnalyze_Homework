// LList.cpp : 定义控制台应用程序的入口点。
//
#include "LList.h"


template<typename E>             //清除head                          
void LList<E>::removehead() {
	while (head != NULL) {
		curr = head;
		head = head->next;
		delete curr;
	}
}

template<typename E>             //清除tail
void LList<E>::removetail() {
	while (tail != NULL) {
		curr = tail;
		tail = tail->prev;
		delete curr;
	}
}

template<typename E>         //输出链表中的元素
void LList<E>::print()
{
	for (int i = 0; i<cnt; i++)
	{
		cout << curr->element << " ";
		curr = curr->next;
	}
	cout << endl;
}


template<typename E>           //输出链表中的元素
void LList<E>::insert(const E&it)
{
	curr->next == new Link<E>(it, curr->next);
	if (tail == curr) tail = curr->next; // New tail
	cnt++;
}

template<typename E>
void LList<E>::append(const E&it)     //tail插入
{
	tail = tail->next = new Link<E>(it, NULL);
	cnt++;
}
//
//template<typename E>
//E LList<E>::remove()
//{
//
//	return E();
//}



template<typename E>
void LList<E>::moveToStart()
{
	curr = head;
}


template<typename E>
void LList<E>::moveToEnd()
{
	curr = tail;
}

template<typename E>
void LList<E>::prev()
{
	if (curr == head) return;
	Link<E>* temp = head;
	while (temp->next!= curr)
	{
		temp = temp->next;
	}
	curr = temp;
}

template<typename E>
void LList<E>::next()
{
	if (curr == tail) return;
	curr = curr->next;
}


template<typename E>
int LList<E>::currPos() const 
{
	int i = 0;
	Link<E>* temp = head;
	while (temp != curr)
	{
		temp = temp->next;
		i++;
	}
	return i;
}


template<typename E>
void LList<E>::moveToPos(int pos) 
{
	Assert((pos >= 0) && (pos <= cnt), "Position out of range");
	int i = 0;
	curr = head;
	while (i<pos)
	{
		curr = curr->next;
		i++;
	}
}

//template<typename E>
//void LList<E>::inversion()
//{
//	Link<E>* temp;
//	temp = head->next;
//	
//}


template<typename E>
void LList<E>::merge(LList a, LList b)
{
	LList<int> LList3(a.cnt + b.cnt);
	a.curr = a.head; a.next();
	b.curr = b.head; b.next();
	while (a.curr != a.tail&&b.curr != b.tail)
	{
		if (a.curr->element < b.curr->element)
		{
			LList3.append(a.curr->element);

			a.next();
		}
		else
		{
			LList3.append(b.curr->element);

			b.next();

		}
	}

	if (a.curr == a.tail)
	{
		while (b.curr != b.tail)
		{
			LList3.append(b.curr->element); b.next();
		}
	}

	if (b.curr == b.tail)
	{
		while (a.curr != a.tail)
		{
			LList3.append(a.curr->element);
			a.next();
		}

	}
	LList3.next();
	LList3.print();
}




int main()
{
	LList<int> LList1;
	LList1.append(12);
	LList1.append(13);
	LList1.append(15);
	LList1.next();
	LList1.print();
	return 0;
}