#include <iostream>
#include "People.h"
#include <cstring>
const int SIZE = 5;
int main()
{
    using std::cin;
    using std::cout;
    using std::endl;
    using std::strchr;
    People::Person* people[SIZE];
    int ct;
    srand(time(0));
    for (ct = 0; ct < SIZE; ct++)
    {
        char choice;
        cout << "Input character:\n"
        << "w: gunslinger s: pokerplayer "
            << "t: baddude q: ending\n";
        cin >> choice;
        while (strchr("wstq", choice) == NULL)
        {
            cout << "Please, input w, s, t or q: ";
            cin >> choice;
        }
        if (choice == 'q')
        {
            //ct--;
            break;
        }

        std::cout << "Input name and surname: ";
        std::string first_name, second_name;
        std::cin >> first_name >> second_name;

        // Choose character
        switch (choice)
        {
        case 'w':
            people[ct] = new People::Gunslinger(first_name, second_name, rand() * 0.5,
                1 + rand() % 5); 
            break;
        case 's':
            people[ct] = new People::PokerPlayer(first_name, second_name);
            break;
        case 't':
            people[ct] = new People::BadDude(first_name, second_name, rand() * 0.5, 1 + rand() % 5);
            break;
        }
    }

    // Output
    std::cout << "\nYour characters: \n";
    for (int i = 0; i < ct; i++)
    {
        cout << endl << endl;
        people[i]->Show();
    }
        
    // Free memory
    /*for (int i = 0; i < ct; ++i)
        delete people[i];*/

    cout << "\nAll the best.\n";
    return 0;
}