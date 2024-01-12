#include <iostream>
#include "strng1.h"
const int ArSize = 10;
const int MaxLen = 81;

int main()
{
    using std::cout;
    using std::cin;
    using std::endl;
    String name;
    cout << "What is your name?\n>> ";
    cin >> name;

    cout << name << ", please, enter up to " << ArSize
        << " short proverbs <or empty string for ending>:\n";
    String sayings[ArSize];
    char temp[MaxLen];
    int i;
    for (i = 0; i < ArSize; ++i)
    {
        cout << i + 1 << ": ";
        cin.get(temp, MaxLen);
        while (cin && cin.get() != '\n')
            continue;
        if (!cin || temp[0] == '\0')
            break;
        else
            sayings[i] = temp;
    }
    int total = i;
    cout << "You have been eneterd next proverbs:\n";
    for (i = 0; i < total; ++i)
        cout << sayings[i][0] << ": " << sayings[i] << endl;

    int shortest = 0, first = 0;
    for (i = 1; i < total; ++i)
    {
        if (sayings[i].length() < sayings[shortest].length())
            shortest = i;
        if (sayings[i] < sayings[first])
            first = i;
    }

    cout << "The shortest proverb:\n" << sayings[shortest] << endl;
    cout << "First proverb in alphabet:\n" << sayings[first] << endl;
    cout << "This program used " << String::HowMany()
        << " String objects. All the best.\n";

    return 0;
}