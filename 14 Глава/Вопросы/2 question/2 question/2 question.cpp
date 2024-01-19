#include <iostream>
#include "Frabjous.h"

int main()
{
    Frabjous frab("I love C++!");
    frab.tell();
    std::cout << std::endl;
    Gloam glom(12, "I really love C++!");
    glom.tell();
}