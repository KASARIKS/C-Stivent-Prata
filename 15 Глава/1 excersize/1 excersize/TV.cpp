#include "TV.h"
#include <iostream>

// Tv methods
bool Tv::volup()
{
	if (volume < MaxVal)
	{
		volume++;
		return true;
	}
	return false;
}

bool Tv::voldown()
{
	if (volume > MinVal)
	{
		volume--;
		return true;
	}
	return false;
}

void Tv::chanup()
{
	if (channel < maxchannel)
		channel++;
	else
		channel = 1;
}

void Tv::chandown()
{
	if (channel > 1)
		channel--;
	else
		channel = maxchannel;
}

void Tv::settings() const
{
	using std::cout;
	using std::endl;
	cout << "TV: " << (state == Off ? "Off" : "On") << endl;
	if (state == On)
	{
		cout << "Volume setting = " << volume << endl;
		cout << "Chanel setting = " << channel << endl;
		cout << "Mode = " << (mode == Antenna ? "antenna" : "cabel") << endl;
		cout << "Input = " << (input == TV ? "TV" : "VCR") << endl;
	}
}

void Remote::buzz(Tv& tv)
{
	buzz_mode = !buzz_mode;
	tv.state = buzz_mode;
}

void Tv::buzz(Remote& r)
{
	r.buzz(*this);
	//r.buzz_mode = !r.buzz_mode;
}