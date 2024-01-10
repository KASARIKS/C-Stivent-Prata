#include <iostream>
#include "golf.h"
#include <vector>

int main()
{
    std::vector<golf> golfs(5);
    for (int i = 0; i < golfs.size(); ++i)
        golfs[i].setgolf();

    for (int i = 0; i < golfs.size(); ++i)
        golfs[i].showgolf();
}