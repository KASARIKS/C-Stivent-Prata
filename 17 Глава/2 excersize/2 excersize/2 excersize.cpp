#include <iostream>
#include <fstream>

int main(int argc, char *argv[])
{
    std::ofstream out(argv[1]);
    char ch;
    std::cin.get(ch);
    for (int i = 0; ch != EOF; ++i)
    {
        out << ch;
        std::cin.get(ch);
        if (i >= 100)
            ch = EOF;
    }
    out.clear();
    out.close();
}