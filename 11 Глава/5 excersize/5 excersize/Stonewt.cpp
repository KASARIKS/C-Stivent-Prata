#include "Stonewt.h"
#include <iostream> 

Stonewt::Stonewt(double lbs)
{
	SetModeStones();
	stone = int(lbs);
	pds_left = int(lbs) % LBS_PER_STN + lbs - int(lbs);
	pounds = lbs;
}

Stonewt::Stonewt(int stn, double lbs, char mode)
{
	if (mode == 'r') SetModeRealPounds();
	else if (mode == 'i') SetModeIntegerPounds();
	else SetModeStones();
	stone = stn;
	pds_left = lbs;
	pounds = stn * LBS_PER_STN + lbs;
}

Stonewt::Stonewt()
{
	SetModeStones();
	stone = pounds = pds_left = 0;
}

void Stonewt::show_lbs() const
{
	std::cout << stone << " stones, " << pds_left << " pounds" << std::endl;
}

void Stonewt::show_stn() const
{
	std::cout << pounds << " pounds." << std::endl;
}

Stonewt::operator int() const
{
	return int(pounds + 0.5);
}

Stonewt::operator double() const
{
	return pounds;
}

Stonewt Stonewt::operator*(Stonewt st) const
{
	return Stonewt(stone * st.stone, pds_left * st.pds_left);
}

Stonewt Stonewt::operator*(double value) const
{
	int stone_copy = stone * value;
	double pds_left_copy = pds_left * value;
	stone_copy += pds_left_copy / LBS_PER_STN;
	pds_left_copy = int(pds_left_copy) % LBS_PER_STN + modf(pds_left_copy, &pds_left_copy);

	return Stonewt(stone_copy, pds_left_copy);
}

void Stonewt::SetMode(char mode)
{
	if (mode != 'i' && mode != 'r' && mode != 's') mode = 's';
	this->mode = mode;
}

Stonewt operator*(double value, Stonewt st)
{
	return st * value;
}

std::ostream &operator<<(std::ostream& os, Stonewt st)
{
	if (st.GetMode() == 's')
		os << st.GetStone() << " stones, " << st.GetPdsLeft() << " pounds.";
	else if (st.GetMode() == 'r')
		os << st.GetPounds() << " real pounds.";
	else if (st.GetMode() == 'i')
		os << static_cast<int>(st.GetPounds()) << " integer pounds.";
	else
		os << "Kick the author's of program ass!";
	return os;
}
