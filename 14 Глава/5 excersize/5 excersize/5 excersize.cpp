﻿#include <iostream>
using namespace std;
#include "emp.h"

int main()
{
    employee em("Trip", "Harris", "Thumper");
    cout << em << endl;
    em.ShowAll();

    manager ma("Amorphia", "Spindragon", "Nuancer", 5);
    cout << ma << endl;
    ma.ShowAll();
    fink fi("Matt", "Oggs", "Oiler", "Juno Barr");
    cout << fi << endl;
    fi.ShowAll();
    highfink hf(ma, "Curly Kew");
    hf.ShowAll();

    cout << "Press anyone key for next phase:\n";
    cin.get();
    highfink hf2;
    hf2.SetAll();

    cout << "Using pointer abstr_emp *:\n";
    abstr_emp* tri[4] = { &em, &fi, &hf, &hf2 };
    for (int i = 0; i < 4; i++)
        tri[i]->ShowAll();

    return 0;
}