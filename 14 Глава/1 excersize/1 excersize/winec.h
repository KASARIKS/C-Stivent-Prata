#pragma once
#include <iostream>
#include <valarray>

template <class T1, class T2>
class Pair
{
private:
	T1 a;
	T2 b;
public:
	T1& first() { return a; }
	T2& second() { return b; }
	T1 first() const { return a; }
	T2 second() const { return b; }
	Pair(const T1& aval, const T2& bval) : a(aval), b(bval) {}
	Pair() {}
};

typedef std::valarray<int> ArrayInt;
typedef Pair<ArrayInt, ArrayInt> PairArray;

class Wine
{
private:
	std::string name;
	PairArray years_and_bottles; // Year of issue and number of bottles
	int age;
public:
	Wine();
	Wine(const char* l, int y, const int yr[], const int bot[]);
	Wine(const char* l, int y);
	void GetBottles(); // Input data
	std::string& Label() { return name; }
	int sum(); // Count total number of bottles
	void Show();
};