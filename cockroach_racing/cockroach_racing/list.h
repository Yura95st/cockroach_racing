#pragma once
#include <iostream>

template <class T>
struct Node
{
	T value;
	Node<T> *Next, *Prev;
};

template <class T>
class List
{
	Node<T> *Tail;
	int nodeCounter;
public:
	List();
	List(List<T> &list);
	~List();
	void show();
	void add(T val);
	int count();
	Node<T>* find(int idx);
	void del(int idx);
	void del();
};

template <class T>
List<T>::List():
	Tail(NULL), nodeCounter(0)
{
}

template <class T>
List<T>::List(List<T> &list):
	Tail(NULL), nodeCounter(0)
{
	for(int i=list.count()-1; i>=0; --i) {
		Node<T>* elem = list.find(i);
		T val = elem->value;
		this->add(val);
	}
}

template <class T>
List<T>::~List()
{  
	if (Tail != NULL) {
		if(nodeCounter > 1) {
			Tail->Next->Prev=NULL;
			while (Tail->Prev != NULL) {
				Node<T> *tmp = Tail;
				Tail=tmp->Prev;
				Tail->Next=NULL;
				delete tmp;
			}
		}
		delete Tail;
	}
}

template <class T>
void List<T>::add(T val)
{
	Node<T> *newElem = new Node<T>;
	newElem->value=val;
	if (Tail!=NULL)
	{
		Node<T> *tmp=Tail->Next;
		newElem->Next=tmp;
		newElem->Prev=Tail;
		tmp->Prev=newElem;		
		Tail->Next=newElem;
	}
	else
	{
		newElem->Next=newElem;
		newElem->Prev=newElem;
		Tail=newElem;
	}
	++nodeCounter;
}


template <class T>
Node<T>* List<T>::find(int idx)
{
	Node<T>* elem;

	if (idx >= nodeCounter) {
		return NULL;
	}
	elem = Tail->Next;

	for(int i=0; i<idx; i++) {
		elem = elem->Next;
	}

	return elem;
}

template <class T>
void List<T>::del(int idx)
{
	if (nodeCounter > 0 && idx < nodeCounter) {
		Node<T>* elem = find(idx);
		Node<T>* tmp = elem->Prev;
		
		tmp->Next = elem->Next;
		tmp = elem->Next;
		tmp->Prev = elem->Prev;
		--nodeCounter;

		delete elem;
	}
}

template <class T>
void List<T>::del()
{
	if (nodeCounter > 0) {
		del(0);
	}
}

template <class T>
int List<T>::count()
{
	return nodeCounter;
}

template <class T>
void List<T>::show()
{
	Node<T> *tmp=Tail->Next;

	while (tmp!=Tail) {
		cout<<tmp->value<<" ";
		tmp=tmp->Next;
	}
	cout<<tmp->value<<" ";
	cout<<"\n";
}