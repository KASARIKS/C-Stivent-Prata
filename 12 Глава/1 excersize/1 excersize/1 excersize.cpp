#include <iostream>
#include "Cow.h"

int main()
{
    Cow cow;
    Cow cow2("Marta", "Eat Corn", 150);
    Cow cow_tmp(cow);
    cow = cow2;
    cow2 = cow_tmp;
    cow.ShowCow();
    std::cout << std::endl;
    cow2.ShowCow();
}