#include <iostream>
#include "Stonewt.h"

int main()
{
    Stonewt stone(10, 8);
    stone.show_lbs();
    stone = 2.0 * stone;
    stone.show_lbs();
}