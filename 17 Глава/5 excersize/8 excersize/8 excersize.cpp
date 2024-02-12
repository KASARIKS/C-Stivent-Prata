// It's modified 8 excersize
// For 5 excersize in capture 17 
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <iterator>
#include <set>
#include <fstream>

int main()
{
    // File names
    const std::string file_mat("mat.dat"), file_pat("pat.dat"), file_general("matnpat.dat");
    std::ifstream file;
    std::ofstream file2;

    // Met's container
    file.open(file_mat);
    std::vector<std::string> Mets;
    std::copy(std::istream_iterator<std::string>(file), std::istream_iterator<std::string>(), std::back_inserter(Mets));
    file.clear();
    file.close();
    
    std::cout << "Input Met's list(empty string for end): " << std::endl;
    std::string tmp;
    while (std::getline(std::cin, tmp) && tmp != "")
        Mets.push_back(tmp);

    // Copy to file
    file2.open(file_mat);
    for (auto it = Mets.begin(); it != Mets.end(); ++it)
        file2 << *it << std::endl;

    file2.clear();
    file2.close();

    std::sort(Mets.begin(), Mets.end());

    // Pet's container
    file.open(file_pat);
    std::vector<std::string> Pets;
    std::copy(std::istream_iterator<std::string>(file), std::istream_iterator<std::string>(), std::back_inserter(Pets));
    file.clear();
    file.close();

    std::cout << "Input Pet's list(empty string for end): " << std::endl;
    while (std::getline(std::cin, tmp) && tmp != "")
        Pets.push_back(tmp);
    
    // Copy to file
    file2.open(file_pat);
    for (auto it = Pets.begin(); it != Pets.end(); ++it)
        file2 << *it << std::endl;

    file2.clear();
    file2.close();

    std::sort(Pets.begin(), Pets.end());

    // Common container
    std::set<std::string> All;

    for (std::vector<std::string>::iterator it = Mets.begin(); it != Mets.end(); ++it)
        All.insert(*it);

    for (std::vector<std::string>::iterator it = Pets.begin(); it != Pets.end(); ++it)
        All.insert(*it);

    // Copy to file
    file2.open(file_general);
    for (auto it = All.begin(); it != All.end(); ++it)
        file2 << *it << std::endl;

    file2.clear();
    file2.close();

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