#include <iostream>
#include "Stonewt.h"

int main()
{
    Stonewt stone(10, 8);
    stone.show_lbs();
    stone = 2.0 * stone;
    stone.show_lbs();
    stone.show_stn();
    
    std::cout << std::endl << "Modify version: " << std::endl;
    Stonewt stone_modify(10, 8);
    std::cout << stone_modify << std::endl;
    stone_modify = 2.0 * stone_modify * 1.2;
    std::cout << stone_modify << std::endl;
    stone_modify.SetMode('r');
    std::cout << stone_modify << std::endl;
    stone_modify.SetMode('i');
    std::cout << stone_modify << std::endl;
} 