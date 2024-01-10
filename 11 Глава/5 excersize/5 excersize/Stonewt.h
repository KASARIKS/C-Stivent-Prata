#pragma once
#include <iostream>
// Class of differnt units
class Stonewt {
private:
	static const int LBS_PER_STN = 14;
	int stone;
	double pds_left, pounds;
	// Integer or real output of number
	// 3 mods. Stones, Real Pounds, Integer Pounds.
	char mode;
	void SetModeStones() { this->mode = 's'; }
	void SetModeRealPounds() { this->mode = 'r'; }
	void SetModeIntegerPounds() { this->mode = 'i'; }
public:
	explicit Stonewt(double lbs);
	explicit Stonewt(int stn, double lbs, char mode='s');
	explicit Stonewt();
	void show_lbs() const;
	void show_stn() const;
	operator int() const;
	operator double() const;
	Stonewt operator*(Stonewt st) const;
	Stonewt operator*(double value) const;
	friend Stonewt operator*(double value, Stonewt st);

	// Getters
	char const GetMode() const { return mode; }
	int const GetStone() const { return stone; }
	double const GetPdsLeft() const { return pds_left; }
	double const GetPounds() const { return pounds; }

	// Setters
	void SetMode(char mode='s');

	friend std::ostream &operator<<(std::ostream& os, Stonewt st);
};