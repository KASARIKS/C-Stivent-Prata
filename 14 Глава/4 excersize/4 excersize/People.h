#pragma once
#include <iostream>
namespace People
{
	class Person
	{
	private:
		std::string first_name, second_name;
	public:
		Person(std::string first_name, std::string second_name);
		Person() : first_name(""), second_name("") {}
		virtual void Show() const;
	};

	class Gunslinger : virtual public Person
	{
	private:
		double reaction_time;
		int number_of_notches;
	public:
		Gunslinger(std::string first_name, std::string second_name, 
			double reaction_time, int number_of_notches);
		Gunslinger() : Person("", ""), reaction_time(0), number_of_notches(0) {};
		virtual double Draw() const;
		virtual void Show() const;
	};

	class PokerPlayer : virtual public Person
	{
	public:
		PokerPlayer(std::string first_name, std::string second_name);
		int Draw() const;
		void Show() const;
	};

	class BadDude : public virtual PokerPlayer, public virtual Gunslinger
	{
	public:
		BadDude(std::string first_name, std::string second_name,
			double reaction_time, int number_of_notches);
		double Gdraw() const;
		double Cdraw() const;
		void Show() const;
	};
}