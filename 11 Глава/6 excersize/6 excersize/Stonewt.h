#pragma once
// Class of differnt units
class Stonewt {
private:
	static const int LBS_PER_STN = 14;
	int stone;
	double pds_left, pounds;
public:
	Stonewt(double lbs);
	Stonewt(int stn, double lbs);
	Stonewt();
	void show_lbs() const;
	void show_stn() const;
	operator int() const;
	operator double() const;
	Stonewt operator*(Stonewt st) const;
	Stonewt operator*(double value) const;
	friend Stonewt operator*(double value, Stonewt st);

	// Compare operations
	bool operator==(Stonewt st) const;
	bool operator!=(Stonewt st) const;
	bool operator<(Stonewt st) const;
	bool operator>(Stonewt st) const;
	bool operator<=(Stonewt st) const;
	bool operator>=(Stonewt st) const;
};