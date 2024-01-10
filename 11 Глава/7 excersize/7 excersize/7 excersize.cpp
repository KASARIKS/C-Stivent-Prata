#include <iostream>
using namespace std;
#include "complex0.h"

int main()
{
    complex a(3.0, 4.0);
    complex c;
    cout << "Input complex number (q for exit):\n";
    while (cin >> c) {
        cout << "c is " << c << '\n';
        cout << "Complex merger is equil " << ~c << '\n';
        cout << "a is equil " << a << '\n';
        cout << "a + c is equil " << a + c << '\n';
        cout << "a - c is equil " << a - c << '\n';
        cout << "a * c is equil " << a * c << '\n';
        cout << "a / c is equil " << 2 * c << '\n';
        cout << "Input complex number (q for exit):\n";
    }
    cout << "Done!\n";
    return 0;
}