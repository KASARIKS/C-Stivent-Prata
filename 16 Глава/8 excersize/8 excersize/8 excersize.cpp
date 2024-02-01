// 8 excersize
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <iterator>
#include <set>

int main()
{
    // Met's container
    std::vector<std::string> Mets;
    std::cout << "Input Met's list(empty string for end): " << std::endl;
    std::string tmp;
    while (std::getline(std::cin, tmp) && tmp != "")
        Mets.push_back(tmp);

    std::sort(Mets.begin(), Mets.end());

    // Pet's container
    std::vector<std::string> Pets;
    std::cout << "Input Pet's list(empty string for end): " << std::endl;
    while (std::getline(std::cin, tmp) && tmp != "")
        Pets.push_back(tmp);

    std::sort(Pets.begin(), Pets.end());

    // Common container
    std::set<std::string> All;

    for (std::vector<std::string>::iterator it = Mets.begin(); it != Mets.end(); ++it)
        All.insert(*it);

    for (std::vector<std::string>::iterator it = Pets.begin(); it != Pets.end(); ++it)
        All.insert(*it);

    // Output containers
    struct Output { void operator()(std::string str) { std::cout << str << std::endl; } } output;
    
    std::cout << "Met's friends: " << std::endl;
    std::for_each(Mets.begin(), Mets.end(), output);
    std::cout << std::endl;

    std::cout << "Pet's friends: " << std::endl;
    std::for_each(Pets.begin(), Pets.end(), output);
    std::cout << std::endl;

    std::cout << "All guests: " << std::endl;
    std::for_each(All.begin(), All.end(), output);
    std::cout << std::endl;
}