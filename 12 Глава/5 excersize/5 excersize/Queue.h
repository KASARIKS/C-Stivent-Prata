#pragma once
// Queue implementation;
class Customer
{
private:
	long int arrive;
	int proccesstime;
public:
	Customer() { arrive = proccesstime = 0; }
	void set(long int when);
	long int when() const { return arrive; }
	int ptime() const { return proccesstime; }
};

typedef Customer Item;

class Queue
{
private:
	struct Node { Item item; struct Node* next; };
	enum { Q_SIZE = 10 };
	Node* front, * rear;
	int items;
	const int qsize;
	Queue(const Queue& q) : qsize(0) {}
	Queue& operator=(const Queue& q) { return *this; }
public:
	Queue(int gs = Q_SIZE);
	~Queue();
	bool isempty() const;
	bool isfull() const;
	int queuecount() const;
	bool enqueue(const Item& item); // Push element
	bool dequeue(Item& item); // Pop element
};