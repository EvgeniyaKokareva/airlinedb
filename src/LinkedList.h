
#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

#include <iostream>
using namespace std;

template <class T>
struct node{
	T data;
	node* next;
};

template <class T>
class LinkedList{
	protected:
		int count;
		node<T> *head, *last;
	public:
		LinkedList();
		bool isEmpty();
		int length();
		T front();
		T back();
		virtual void insert(T&);
		void deleteNode(T&);
		void destroylist();
		LinkedList<T>& operator=(LinkedList<T>&);

		template <class U>
		friend ostream& operator<<(ostream& os, LinkedList<U>& list);
		virtual ~LinkedList();
};

// Implementation below

template <class T>
LinkedList<T>::LinkedList(){
     head = last = NULL;
     count = 0;
}

template <class T>
bool LinkedList<T>::isEmpty(){
	return head==NULL;
}

template <class T>
int LinkedList<T>::length(){
	return count;
}

template <class T>
T LinkedList<T>::front(){
	return head->data;
}

template <class T>
T LinkedList<T>::back(){
	return last->data;
}

template <class T>
void LinkedList<T>::insert(T& item){
	node<T> *newnode = new node<T>;
	newnode->data = item;
	newnode->next = NULL;
	if(head==NULL){
		head = last = newnode;
	}else{
		last->next = newnode;
		last = newnode;
	}
	count++;
}

template <class T>
void LinkedList<T>::deleteNode(T& item){
	if(head != NULL){
		if(head->data == item){
			node<T>* p = head;
			head = head->next;
			delete p;
			count--;
			if(head==NULL) last = NULL;
		}else{
			node<T>* p = head;
			node<T>* q = p->next;
			while(q!=NULL && q->data != item){
				p = q;
				q = q->next;
			}
			if(q!=NULL){
				p->next = q->next;
				count--;
				if(last == q) last = p;
				delete q;
			}
		}
	}
}

template <class T>
void LinkedList<T>::destroylist(){
	node<T> *p;
	while(head != NULL){
		p = head;
		head = head->next;
		delete p;
	}
	last = NULL;
	count = 0;
}
template <class T>
LinkedList<T>& LinkedList<T>::operator=(LinkedList<T>& list){
	if(this!= &list){
		copylist(list);
	}
	return *this;
}

template <class T>
ostream& operator<<(ostream& os, LinkedList<T>& list){
	node<T> *p = list.head;
	while(p!= NULL){
		os<<p->data<<" "<<endl;
		p = p->next;
	}

	return os;
}

template <class T>
LinkedList<T>::~LinkedList(){
	destroylist();
}


#endif /* LINKEDLIST_H_ */
