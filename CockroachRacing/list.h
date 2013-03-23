#include <iostream>

template <class T>
struct Node
{
	T value;
	Node *Next,*Prev;
};

template <class T>
class List
{
	Node *Tail;
	int nodeCounter;
public:
	List():Tail(NULL),nodeCounter(0){};
	~List();
	void show();
	void add(int x);
	int count();
	Node* find(int idx);
	void del(int idx);
	void del();
};