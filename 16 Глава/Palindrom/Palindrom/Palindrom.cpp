#include <iostream>
#include <algorithm>

// Check is string a palindrom
bool is_palindrom(std::string& str);

int main()
{
	std::cout << "Input string: ";
	std::string str;
	std::cin >> str;
	std::cout << (is_palindrom(str) ? "It's palindrom." : "It isn't palindrom.") << std::endl;
}

bool is_palindrom(std::string& str)
{
	std::string rev;

	// transform string to string without don't need symbols and upper case letters
	for (std::string::iterator it = str.begin(); it != str.end(); ++it)
	{
		if (!isalpha(*it)) continue;
		*it = tolower(*it);
		rev.push_back(*it);
	}
	
	return rev == std::string(rev.rbegin(), rev.rend());
}