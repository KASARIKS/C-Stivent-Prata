// This is modified excersize 5 from chapter 14
// For 6 excersize chapter 17
#include <iostream>
#include "emp.h"
#include <fstream>
#include <cstdlib>

int main()
{

    // File data amd output
    const std::string file_name("employeers.txt");
    std::fstream file(file_name, std::ios::in);
    std::string file_line;

    std::cout << "Employers from file: " << std::endl;
    while (getline(file, file_line))
    {
        std::cout << file_line << std::endl;
    }
    
    std::cout << "-------------------------" << std::endl;
    std::cout << std::endl;

    file.clear();
    file.close();

    // Input data
    const int MAX = 10;
    abstr_emp* employees[MAX];

    struct employee_info 
    {
        std::string first, second, third;
    } employee_info;

    int emp;

    for (emp = 0; emp < 10 ; ++emp)
    {
        // Menu
        char ch = 'a';
        std::cout << "1. employee" << std::endl;
        std::cout << "2. manager" << std::endl;
        std::cout << "3. fink" << std::endl;
        std::cout << "4. highfink" << std::endl;
        std::cout << "Another symbol to exit." << std::endl;
        std::cout << "Please, choose type of employee: ";

        std::cin >> ch;

        if (ch < '1' || ch > '4')
            break;


        // Input name of employee
        std::cout << "Please, input full name: ";
        std::cin >> employee_info.first >> employee_info.second >> employee_info.third;
        std::string manager_fname, manager_lname;

        switch (ch)
        {
        case '1':
            employees[emp] = new employee(employee_info.first, employee_info.second, employee_info.third);
            break;
        case '2':
            employees[emp] = new manager(employee_info.first, employee_info.second, employee_info.third);
            break;
        case '3':
            std::cout << "Please, input first and last name: ";
            
            std::cin >> manager_fname >> manager_lname;
            employees[emp] = new fink(employee_info.first, employee_info.second, employee_info.third, manager_fname + " " + manager_lname);
            break;
        case '4':
            std::cout << "Please, input first and last name: ";

            std::cin >> manager_fname >> manager_lname;
            employees[emp] = new highfink(employee_info.first, employee_info.second, employee_info.third, 
                manager_fname + " " + manager_lname, rand() % 10);
            break;
        }
    }

    // Write to file
    file.open(file_name, std::ios::app);

    for (int i = 0; i < emp; ++i)
    {
        employees[i]->writeall(file);
    }

    file.clear();
    file.close();

    // free memory
    for (int i = 0; i < emp; ++i)
        delete employees[i];

    /*employee em("Trip", "Harris", "Thumper");
    cout << em << endl;
    em.ShowAll();
    std::cout << std::endl;

    manager ma("Amorphia", "Spindragon", "Nuancer", 5);
    cout << ma << endl;
    ma.ShowAll();
    std::cout << std::endl;

    fink fi("Matt", "Oggs", "Oiler", "Juno Barr");
    cout << fi << endl;
    fi.ShowAll();
    std::cout << std::endl;

    highfink hf(ma, "Curly Kew");
    hf.ShowAll();
    std::cout << std::endl;

    cout << "Press anyone key for next phase:\n";
    cin.get();
    highfink hf2;
    hf2.SetAll();

    cout << "Using pointer abstr_emp *:\n";
    abstr_emp* tri[4] = { &em, &fi, &hf, &hf2 };
    for (int i = 0; i < 4; i++)
        tri[i]->ShowAll(), std::cout << std::endl;*/

    return 0;
}