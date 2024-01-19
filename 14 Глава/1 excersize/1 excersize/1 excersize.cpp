#include <iostream>
#include "winec.h"

int main()
{
    using std::cin;
    using std::cout;
    using std::endl;
    cout << "Input name of wine: ";
    char lab[50];
    cin.getline(lab, 50);
    cout << "Input number of harvests: ";
    int yrs;
    cin >> yrs;
    Wine holding(lab, yrs);
    holding.GetBottles();
    holding.Show();
    const int YRS = 3;
    int y[YRS] = { 1993, 1995, 1998 };
    int b[YRS] = { 48, 60, 72 };
    Wine more("Gushing Grape Red", YRS, y, b);
    more.Show();
    cout << "Total number of bottles " << more.Label() << ": " << more.sum() << endl;
    cout << "All the best!" << std::endl;
}