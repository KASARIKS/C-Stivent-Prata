#pragma once
#include <iostream>
class Time 
{
private:
	int hours, minutes;
public:
	Time();
	Time(int h, int m = 0);
	void AddMin(int m);
	void AddHr(int h);
	void Reset(int h = 0, int m = 0);
	friend Time operator+(const Time& t, const Time& t2);
	friend Time operator-(const Time& t, const Time& t2);
	friend Time operator*(const Time& t, double m);
	// Operators with another side of definition
	friend Time operator*(double m, const Time& t);
	friend std::ostream& operator<<(std::ostream& os, const Time& t);
};