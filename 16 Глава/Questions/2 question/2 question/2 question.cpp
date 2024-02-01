#include <iostream>
#include <string>

void foo(std::string& str);

int main()
{
    std::string test_string("This is the test string.");
    foo(test_string);
    std::cout << test_string << std::endl;
}

void foo(std::string& str)
{
    for (std::string::iterator iter = str.begin(); iter != str.end(); ++iter)
        *iter = toupper(*iter);
}