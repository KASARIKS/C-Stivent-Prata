/*Модифицируйте листинг 15.11 таким образом, чтобы два типа исключений 
бьши классами, производными от класса logic_error, 
определенного в заголовочном файле <stdexcept>. 
Сделайте, чтобы каждый метод what () отображал имя функции и суть проблемы. 
Объект исключения не должен содержать значение ошибки, 
а должен просто поддерживать метод what ( ) .*/
#include <iostream>
#include <cmath>
#include "exc_mean.h"

double hmean(double a, double b) throw(bad_hmean);
double gmean(double a, double b) throw(bad_gmean);

int main()
{
    using std::cout;
    using std::cin;
    using std::endl;
    double x, y, z;
    cout << "Enter 2 numbers: ";
    while (cin >> x >> y)
    {
        try
        {
            z = hmean(x, y);
            cout << "Average harmonic " << x << " and " << y << " equil " << z << endl;
            cout << "Average geometric " << x << " and " << y << " equil " 
                << gmean(x, y) << endl;
            cout << "Enter next sequince of numbers <q for ending>: ";
        }
        catch (bad_hmean& bg)
        {
            bg.what();
            cout << "Re-enter: \n";
            continue;
        }
        catch (bad_gmean& hg)
        {
            cout << hg.what();
            cout << "Using values: " << hg.v1 << ", " << hg.v2 << endl;
            cout << "Sorry, you don't have to try anymore.\n";
            break;
        }
    }
    cout << "All the best!\n";
    return 0;
}

double hmean(double a, double b) throw(bad_hmean)
{
    if (a == -b)
        throw bad_hmean(a, b);
    return 2.0 * a * b / (a + b);
}

double gmean(double a, double b) throw(bad_gmean)
{
    if (a < 0 || b < 0)
        throw bad_gmean(a, b);
    return std::sqrt(a * b);
}