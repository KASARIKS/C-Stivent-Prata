#include "MyList.h"

MYLIST::MyList::MyList()
{
	count = 0;
	head = new Node;
}

MYLIST::MyList::MyList(double value)
{
	count = 1;
	head = new Node;
	head->value = value;
	current = new Node;
	head->next = current;
}

void MYLIST::MyList::Add(double value)
{
	if (count == 0) {
		head->value = value;
		current = new Node;
		head->next = current;
	}
	else {
		current->next = new Node;
		current->value = value;
		current = current->next;
	}
	++count;
}

bool MYLIST::MyList::IsEmpty()
{
	return count == 0;
}

bool MYLIST::MyList::IsFull()
{
	return count == MAXCOUNT;
}

#include <iostream>

void MYLIST::MyList::WalkThrow(void (*foo)(Node* el))
{
	current = head;
	for (int i = 0; i < count; ++i) {
		foo(current);
		current = current->next;
	}
}

MYLIST::MyList::~MyList()
{
	Node *ptr = head;
	for (int i = 0; i <= count; ++i) {
		ptr = head->next;
		delete head;
		head = ptr;
	}
	ptr = 0;
}
