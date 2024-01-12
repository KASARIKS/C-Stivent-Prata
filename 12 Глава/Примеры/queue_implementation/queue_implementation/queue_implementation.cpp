// Queue implementation.
// Bank for example
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "queue.h"
const int MIN_PER_HR = 60;
bool newcustomer(double x); // is there a new customer

int main()
{
    // Include neccesarry libraries
    using std::cin;
    using std::cout;
    using std::endl;
    using std::ios_base;
    std::srand(std::time(0));

    // Enter neccesarry data
    cout << "Training example: ATM of Bank of Heather\n";
    cout << "Enter maximum size of queue: ";
    int qs;
    cin >> qs;
    Queue line(qs);

    cout << "Input number of simulated hours: ";
    int hours;
    cin >> hours;
    long int cyclelimit = MIN_PER_HR * hours;

    cout << "Enter average number of customers per hour: ";
    double perhour;
    cin >> perhour;
    double min_per_hours;
    min_per_hours = MIN_PER_HR / perhour;

    // Fill data with 0
    // Dynamic data(Updating during simulating)
    Item temp;
    long int turnaways = 0, customers = 0;
    long int served = 0, sumline = 0, line_wait = 0;
    int wait_time = 0;

    // Simulating
    for (int cycle = 0; cycle < cyclelimit; cycle++)
    {
        if (newcustomer(min_per_hours))
        {
            if (line.isfull())
                turnaways++;
            else
            {
                customers++;
                temp.set(cycle);
                line.enqueue(temp);
            }
        }
        if (wait_time <= 0 && !line.isempty())
        {
            line.dequeue(temp);
            wait_time = temp.ptime();
            line_wait += cycle - temp.when();
            served++;
        }
        if (wait_time > 0)
            wait_time--;
        sumline += line.queuecount();
    }

    if (customers > 0)
    {
        cout << "Accepted: " << customers << endl;
        cout << "Served: " << served << endl;
        cout << "Sended: " << turnaways << endl;
        cout << "Average size of queue: ";
        cout.precision(2);
        cout.setf(ios_base::fixed, ios_base::floatfield);
        cout.setf(ios_base::showpoint);
        cout << (double)sumline / cyclelimit << endl;
        cout << "Average time of waiting: " << (double)line_wait / served << " minutes" << endl;
    }
    else
        cout << "No customers!" << endl;
    cout << "Done!" << endl;

    return 0;
}

bool newcustomer(double x) 
{
    return (std::rand() * x / RAND_MAX < 1);
}