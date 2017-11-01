#include "LList.h"
#include<time.h>


template<typename E>             //���head                          
void LList<E>::removehead(){
	while(head!=NULL){
		curr=head;
		head=head->next;
		delete curr;
	}
}

template<typename E>             //���tail
void LList<E>::removetail(){
		while(tail!=NULL){
		curr=tail;
		tail=tail->prev;
		delete curr;
	}
}


template<typename E>           //��������е�Ԫ��
void LList<E>::print(){
	Link<E>* temp = head->next;
	for(int i=0;i<cnt;i++){
		cout<< temp->element<<" ";
		temp = temp->next;
	}
	cout<<endl;
} 
	
template<typename E>            //��curr����Ԫ��
void LList<E>::insert(const E&it){
	curr->next=curr->next->prev=new Link<E>(it,curr,curr->next);
	cnt++;
}
		
template<typename E>            //����β����Ԫ��
void LList<E>::append(const E&it){
	tail->prev=tail->prev->next=new Link<E>(it,tail->prev,tail);
    cnt++;
}
		
template<typename E>            //�Ƴ�
void LList<E>::remove(){           
	//cout << "11 14541 345 89 121 " << endl;
	cnt--;
	curr->next = curr->next->next;
}
		
template<typename E>           //ָ����ͷ
void LList<E>::moveToStart(){  
	curr=head;
}
		
template<typename E>          //ָ����β
void LList<E>:: moveToEnd(){
	curr=tail;
}
		
template<typename E>          //ָ��ǰһ��
void LList<E>::prev(){
	if(curr!=head)
		curr=curr->prev;
}
		
template<typename E>         //ָ���һ��
void LList<E>:: next(){
	if(curr!=tail)
		curr=curr->next;
}
		
template<typename E>
int LList<E>::currPos()const{
	Link<E>*temp=head;
	int i;
	for(i=0;curr!=temp;i++)
		temp=temp->next;
	return i;
}
	
template<typename E>
void LList<E>:: moveToPos(int pos){
	curr=head;
	for(int i=0;i<pos;i++)
		curr=curr->next;
}

template <typename E>                   
void LList<E>::inversion(int size){
	curr=head->next;                  
	tail=tail->prev;                  
	for(int i=0;i<size/2;i++){
		E temp=curr->element;         
		curr->element=tail->element;
		tail->element=temp;

		curr=curr->next;             

		tail=tail->prev;             

	}
	moveToStart();               
	next();
	cout<<"���ú��������Ԫ��Ϊ��"<<endl;
	print();                        //���
}

template<typename E>
void LList<E>::merge(LList a,LList b) 
{
	LList<int> list3(a.cnt+b.cnt);
	a.curr = a.head; a.next();
		b.curr = b.head; b.next();
	while (a.curr != a.tail&&b.curr != b.tail)
	{
		if (a.curr->element < b.curr->element)
		{
			list3.append(a.curr->element);
			
			a.next();
		}
		else
		{
			list3.append(b.curr->element);
			
			b.next();

		}
	}

	if (a.curr ==a.tail)
	{
		while (b.curr != b.tail)
		{
			list3.append(b.curr->element);b.next();
		}
	}

	if (b.curr == b.tail)
	{
		while (a.curr != a.tail)
		{
			list3.append(a.curr->element);
			a.next();
		}

	}
	list3.next();
	list3.print();
}
	


int main(int grgc, char** argv){
	int const listsize=6;
    LList<int> list1(listsize);

	list1.append(11);
	list1.append(23);
	list1.append(14541);
	list1.append(345);
	list1.append(89);
	list1.append(121);
	list1.next();
	list1.print();
	list1.moveToPos(2);
	list1.remove();
	list1.print();
	system("pause");
    return 0;

}
	