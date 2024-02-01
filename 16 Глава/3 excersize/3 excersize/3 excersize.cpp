#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cctype>
#include <fstream>
#include <iterator>
#include <vector>

using std::string;

int main()
{
    std::vector<string> wordlist(10);
    using std::cout;
    using std::cin;
    using std::tolower;
    using std::endl;

    std::ifstream file("test_words.txt");
    for (int i = 0; i < 10; ++i)
        file >> wordlist[i];

    std::srand(std::time(0));
    char play;
    cout << "Want to play in words? <y/n> ";
    cin >> play;
    play = tolower(play);
    
    while (play == 'y')
    {
        string target = wordlist[std::rand() % 10];
        int length = target.length();
        string attempt(length, '-');
        string badchars;
        int guesses = 6;
        cout << "Guess my secrete word. It contains " << length
            << " letters, and you can guess\n"
            << " one letter for one try. You have " << guesses
            << " wrong guesings.\n";
        cout << "Your word is: " << attempt << endl;

        while (guesses > 0 && attempt != target)
        {
            char letter;
            cout << "Guess the letter: ";
            cin >> letter;
            if (badchars.find(letter) != string::npos
                || attempt.find(letter) != string::npos)
            {
                cout << "You have already guessed her. Try again.\n";
                continue;
            }
            int loc = target.find(letter);
            if (loc == string::npos)
            {
                cout << "Wrong!\n";
                --guesses;
                badchars += letter;
            }
            else
            {
                cout << "Right!\n";
                attempt[loc] = letter;
                loc = target.find(letter, loc + 1);
                while (loc != string::npos)
                {
                    attempt[loc] = letter;
                    loc = target.find(letter, loc + 1);
                }
            }

            cout << "Your word is: " << attempt << endl;
            if (attempt != target)
            {
                if (badchars.length() > 0) 
                {
                    cout << "Wrong guesses: " << badchars << endl;
                    cout << guesses << " tryes left\n";
                }
            }
        }

        if (guesses > 0)
            cout << "Guessed!\n";
        else
            cout << "Sorry, but the word is: " << target << ".\n";

        cout << "Want to play again? <y/n> ";
        cin >> play;
        play = tolower(play);
    } 

    cout << "Good luck!\n";
    return 0;
}