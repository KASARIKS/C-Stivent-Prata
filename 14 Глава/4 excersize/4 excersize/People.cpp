#include "People.h"

// People methods
People::Person::Person(std::string first_name, std::string second_name)
{
	this->first_name = first_name;
	this->second_name = second_name;
}

void People::Person::Show() const
{
	std::cout << "First name: " << first_name << std::endl;
	std::cout << "Second name: " << second_name << std::endl;
}

// Gunslinger methods
People::Gunslinger::Gunslinger(std::string first_name, std::string second_name, 
	double reaction_time, int number_of_notches) : Person(first_name, second_name)
{
	this->reaction_time = reaction_time;
	this->number_of_notches = number_of_notches;
}

double People::Gunslinger::Draw() const
{
	return reaction_time;
}

void People::Gunslinger::Show() const
{
	Person::Show();
	std::cout << "Reaction time: " << reaction_time << " ms";
}

// PokerPlayer methods
People::PokerPlayer::PokerPlayer(std::string first_name, std::string second_name) :
	Person(first_name, second_name)
{
}

int People::PokerPlayer::Draw() const
{
	srand(time(0));
	return 1 + rand() % 52;
}

void People::PokerPlayer::Show() const
{
	Person::Show();
}

// BadDude methods

People::BadDude::BadDude(std::string first_name, std::string second_name, 
	double reaction_time, int number_of_notches) : Person::Person(first_name, second_name),
	Gunslinger(first_name, second_name, reaction_time, number_of_notches),
	PokerPlayer(first_name, second_name)
{
}

double People::BadDude::Gdraw() const
{
	return Gunslinger::Draw();
}

double People::BadDude::Cdraw() const
{
	return PokerPlayer::Draw();
}

void People::BadDude::Show() const 
{
	Gunslinger::Show();
}
