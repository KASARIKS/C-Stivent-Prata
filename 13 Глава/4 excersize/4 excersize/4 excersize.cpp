// 4 excersize.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
#include <iostream>
#include "Port.h"

int main()
{
    Port first("Bardo", "classic", 12);
    first += 4;
    std::cout << first << std::endl;
    VintagePort second("Ne bardo", 15, "Kekker", 2000);
    std::cout << second << std::endl;
    first = second;
    std::cout << first << std::endl;
}