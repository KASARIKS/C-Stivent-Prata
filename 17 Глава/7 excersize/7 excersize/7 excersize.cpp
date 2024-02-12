#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <string>

void ShowStr(const std::string& str);
void GetStrs(std::ifstream& fin, std::vector<std::string>& vistr);

class Store
{
private:
    std::ofstream& fout;
public:
    std::string info;
    Store(std::ofstream& fout);
    void operator() (const std::string& str);
};

int main()
{
    using namespace std;
    vector<string> vostr;
    string temp;

    cout << "Input strings (or empty string for ending):\n";
    while (getline(cin, temp) && temp[0] != '\0')
        vostr.push_back(temp);
    cout << "Your input.\n";
    for_each(vostr.begin(), vostr.end(), ShowStr);

    ofstream fout("strings.dat", ios_base::out | ios_base::binary);
    for_each(vostr.begin(), vostr.end(), Store(fout));
    fout.close();

    vector<string> vistr;
    ifstream fin("strings.dat", ios_base::in | ios_base::binary);
    if (!fin.is_open())
    {
        cerr << "Can't open file for input.\n";
        exit(EXIT_FAILURE);
    }

    GetStrs(fin, vistr);
    cout << "\nStrings, that was read from file:\n";
    for_each(vistr.begin(), vistr.end(), ShowStr);

    return 0;
}

void ShowStr(const std::string& str)
{
    std::cout << str << std::endl;
}

Store::Store(std::ofstream& fout) : fout(fout)
{
    
}

void Store::operator()(const std::string& str)
{
    fout << str;
}


void GetStrs(std::ifstream& fin, std::vector<std::string>& vistr)
{
    std::string line;
    while (std::getline(fin, line))
    {
        vistr.push_back(line);
    }
}