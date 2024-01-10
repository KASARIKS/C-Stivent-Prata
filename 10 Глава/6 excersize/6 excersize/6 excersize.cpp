#include <iostream>
#include "Move.h"

int main()
{
    Move first(1, 2);
    first.showmove();
    first.reset(2, 4);
    first.showmove();
    Move second = first.add(first);
    second.showmove();
}