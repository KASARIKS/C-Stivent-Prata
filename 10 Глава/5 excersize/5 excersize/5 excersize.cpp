#include <iostream>
#include "Stack.h"

int main()
{
    Stack st;
    char ch;
    customer po;
    double total = 0;
    std::cout << "Input A for adding task,\nP - for ending task, Q - for exit.\n";
    while (std::cin >> ch && toupper(ch) != 'Q') {
        while (std::cin.get() != '\n') continue;
        if (!isalpha(ch)) {
            std::cout << '\a';
            continue;
        }
        switch (ch) {
        case 'A':
        case 'a':
            std::cout << "Input id of task for adding: ";
            std::cin >> po.fullname >> po.payment;
            if (st.isfull())
                std::cout << "Stack is full" << std::endl;
            else
                st.push(po);
            break;
        case 'P':
        case 'p':
            if (st.isempty())
                std::cout << "Stack is empty" << std::endl;
            else {
                st.pop(po);
                total += po.payment;
                std::cout << po.fullname << " poped. " << total << "$ total." << std::endl;
            }
            break;
        }
        std::cout << "Input A for adding task,\nP - for ending task, Q - for exit.\n";
    }
    std::cout << "Fuck you!" << std::endl;
}