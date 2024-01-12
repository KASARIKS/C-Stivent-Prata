// Now not bad string
#include <iostream>
using std::cout;
#include "strngbad.h"
void callme1(StringBad& rsb);
void callme2(StringBad& rsb);

int main()
{
    using std::endl;
    StringBad headline1("Celery crept up at midnight");
    StringBad headline2("Lettuce is out hunting");
    StringBad sports("Spinate settled in a three-liter jam with dollars");
    cout << "Headline1: " << headline1 << endl;
    cout << "Headline2: " << headline2 << endl;
    cout << "Sports: " << sports << endl;
    callme1(headline1);
    cout << "Headline1: " << headline1 << endl;
    callme2(headline2);
    cout << "Headline2: " << headline2 << endl;
    cout << "Initializing one object to another:\n";
    StringBad sailor = sports;
    cout << "Sailor: " << sailor << endl;
    cout << "Asigning one object to another:\n";
    StringBad knot;
    knot = headline1;
    cout << "Knot: " << knot << endl;
    cout << "End of main() function" << endl;
    return 0;
} 

void callme1(StringBad& rsb) {
    cout << "The string passed by reference:\n";
    cout << "\"" << rsb << "\"\n";
}

void callme2(StringBad& rsb) {
    cout << "The string passed by value:\n";
    cout << "\"" << rsb << "\"\n";
}