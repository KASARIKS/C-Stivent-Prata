#pragma once
#include <queue>
// template of QueueTp with listings 14.10, 14.12

template <typename QueueTp>
class Queue
{
private:
	std::queue<QueueTp> elems;
	int size;
public:
	Queue();
	void Push(QueueTp& el); // Push element to the end
	void Push(QueueTp* el);
	void Pop(); // Delete element from begin
	QueueTp& Front();
};

template <typename QueueTp>
Queue<QueueTp>::Queue()
{
	size = 0;
}

template<class QueueTp>
void Queue<QueueTp>::Push(QueueTp& el)
{
	elems.push(el);
}

template <class QueueTp>
void Queue<QueueTp>::Push(QueueTp* el)
{
	elems.push(*el);
}

template<class QueueTp>
void Queue<QueueTp>::Pop()
{
	elems.pop();
}

template<class QueueTp>
QueueTp& Queue<QueueTp>::Front()
{
	return elems.front();
}