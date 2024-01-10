#include <iostream>

static int times_execute = 0;

void print(std::string message, int flag = 0);

int main()
{
    print("Hello kitty");
    print("Hello kitty");
    print("Fuck you!", -1);
}

void print(std::string message, int flag) {
    ++times_execute;
    int count = (flag != 0) ? times_execute : 1;
    
    for (int i = 0; i < count; ++i)
        std::cout << message << std::endl;
}