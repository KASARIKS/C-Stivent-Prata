#include <iostream>
#include "Plorg.h"
#include <string>

int main()
{
    std::string name;
    std::cout << "Input plorg name: ";
    getline(std::cin, name);
    int ci;
    std::cout << "Input plorg ci: ";
    std::cin >> ci;
    PLORG::Plorg plorg(name, ci);
    plorg.SetCI(ci + 1);
    plorg.SayInfo();
}