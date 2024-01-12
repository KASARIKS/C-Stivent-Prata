// И тут я вообще ахуел
#include <iostream>
#include <string>
#include <new>

const int BUF = 512;

class Test
{
private:
    std::string words;
    int number;
public:
    Test(const std::string& words = "Test object", int number = 0)
    {
        this->words = words;
        this->number = number;
    }
    void print() const
    {
        std::cout << words << " " << number << std::endl;
    }
};

int main()
{
    // Ну это пиздец просто, давайте вообще на ассемблере писать, хули нам
    char* buffer = new char[BUF];
    Test* pc = new (buffer) Test("Second test", 34);
    Test* pc2 = new (buffer + sizeof(*pc)) Test("First test", 12);
    pc->print();
    pc2->print();

    delete[] buffer;
}