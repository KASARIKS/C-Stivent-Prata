#include <iostream>
#include <fstream>
#include <string>

int main()
{
    std::cout << "Input first file name: ";
    std::string file_name_1;
    std::cin >> file_name_1;
    std::cout << "Input second file name: ";
    std::string file_name_2;
    std::cin >> file_name_2;
    std::ifstream file1(file_name_1);
    std::ofstream file2(file_name_2);

    std::string file1_data;
    
    while (!file1.eof())
    {
        std::getline(file1, file1_data);
        file2 << file1_data << std::endl;
    }

    file1.clear();
    file2.clear();
    file1.close();
    file2.close();

    return 0;
}