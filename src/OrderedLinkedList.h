
#ifndef ORDEREDLINKEDLIST_H_
#define ORDEREDLINKEDLIST_H_

#include "LinkedList.h"
#include <iostream>
using namespace std;

template <class T>
class OrderedLinkedList: public LinkedList<T> {

public:

	void insert (T& item);
	T* searchNode(T& item);
	void print();
};

// IMPLEMENTATION BELOW

template <class T>
void OrderedLinkedList<T> :: insert (T& item){
	node<T> *newnode = new node<T>;
	newnode->data = item;
	newnode->next = NULL;
	if(this->head == NULL) {
		this->head = this->last = newnode;
	} else if (this->head->data > item) {
		newnode->next = this->head;
		this->head = newnode;
	} else {
		node<T>* p = this->head;
		while(p->next != NULL){
			if(p->next->data > item){
				break;
			}
			p = p->next;
		}
		newnode->next = p->next;
		p->next = newnode;
	}
	this->count++;
}

template <class T>
T* OrderedLinkedList<T> :: searchNode(T& item){  // pointer and return NULL
	node<T>* p = this->head;
	while(p != NULL){
		if(p->data == item){
			return &(p->data);
		}
		p = p->next;
	}
	return NULL;
}

template <class T>
void OrderedLinkedList<T> :: print(){
	node<T>* p = this->head;
	while(p != NULL){
		cout << p->data << endl;
		p = p->next;
	}
}

#endif /* ORDEREDLINKEDLIST_H_ */
