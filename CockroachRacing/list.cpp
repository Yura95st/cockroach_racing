#include "list.h"

template <class T>
List<T>::~List()
{  
	while (Tail) {
		Node *tmp = Tail;		
		Tail=Tail->Prev;
		delete tmp;
	}
}

template <class T>
void List<T>::add(int val)
{
	Node *newElem = new Node;
	newElem->value=val;
	if (Tail!=NULL)
	{
		Node *tmp=Tail->Next;
		newElem->Next=tmp;
		tmp->Prev=newElem;
		newElem->Prev=Tail;
		Tail->Next=newElem;
		Tail=newElem;
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
Node* List<T>::find(int idx)
{
	Node* elem;

	if (idx >= nodeCounter) {
		return NULL;
	}
	elem = Tail->Next;

	for(int i=1; i<idx; i++) {
		elem = elem->Next;
	}

	return elem;
}

template <class T>
void List<T>::del(int idx)
{
	if (nodeCounter > 0 && idx < nodeCounter) {
		Node* elem = find(idx);
		Node* tmp = elem->Prev;
		
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
	int idx = nodeCounter-1;
	if (idx >= 0) {
		del(idx);
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
	Node *tmp=Tail->Next;

	while (tmp!=Tail) {
		cout<<tmp->value<<" ";
		tmp=tmp->Next;
	}
	cout<<"\n";
}