#include <iostream>

int main()
{
    char symbol;
    int count;
    std::cin.get(symbol);
    for (count = 0; symbol != '$'; ++count)
        std::cin.get(symbol);

    std::cout << count << std::endl;
}