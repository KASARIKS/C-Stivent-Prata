#include <iostream>
#include <fstream>
#include <string>

int main()
{
    // Start data
    std::ifstream first("first.txt"), second("second.txt");
    std::ofstream third("third.txt");
    std::string tmp_string(""), tmp_string2("");

    // Read
    while (!first.eof() || !second.eof())
    {
        std::getline(first, tmp_string);
        std::getline(second, tmp_string2);
        tmp_string += " " + tmp_string2;
        third << tmp_string << std::endl;
        tmp_string = tmp_string2 = "";
    }

    // Close files
    first.clear();
    second.clear();
    third.clear();
    first.close();
    second.close();
    third.close();
}