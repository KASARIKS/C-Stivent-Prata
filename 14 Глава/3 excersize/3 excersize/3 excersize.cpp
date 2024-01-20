#include <iostream>
#include "QueueTp.h"
#include "Worker.h"

int main()
{
    Worker worker, worker1, worker2;
    Queue<Worker> queue;
    queue.Push(&worker);
    queue.Push(&worker1);
    queue.Push(&worker2);
    std::cout << queue.Front().id << std::endl;
    queue.Pop();
    std::cout << queue.Front().id << std::endl;
    queue.Pop();
    std::cout << queue.Front().id << std::endl;
}