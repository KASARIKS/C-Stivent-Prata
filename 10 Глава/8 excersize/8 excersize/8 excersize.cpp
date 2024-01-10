#define __CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#define DEBUG_NEW new(_NORMAL_BLOCK, __FILE__, __LINE__)
#define new DEBUG_NEW
#include <iostream>
#include "MyList.h"

void print(MYLIST::Node* el) {
    std::cout << el->value << std::endl;
}

int main()
{
    for (int i = 0; i < 100000000; ++i) {
        MYLIST::MyList test_list;
        for (int i = 0; i < 100000; ++i) {
            test_list.Add(i);
        }
        std::cout << i << std::endl;
    }
    _CrtDumpMemoryLeaks();
    return 0;
}