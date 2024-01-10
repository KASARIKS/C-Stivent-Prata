#include <iostream>
#include "Person.h"

int main()
{
    Person one, two("Huilusha1234"), three("Golovko", "Yaroslav");
    std::cout << "one: " << std::endl;
    one.Show();
    one.FormalShow();
    std::cout << std::endl;
    std::cout << "two: " << std::endl;
    two.Show();
    two.FormalShow();
    std::cout << std::endl;
    std::cout << "three: " << std::endl;
    three.Show();
    three.FormalShow();
}