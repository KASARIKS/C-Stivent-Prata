#pragma once

// Player's info
class golf {
private:
	static const int LEN = 40;
	char m_fullname[LEN];
	int m_handicap;
public:
	// Set player's info
	void setgolf(const char* name, int hc);

	// Input player's info
	int setgolf();

	// Set new number of handicaps
	void handicap(int hc);

	// Output player's info
	void showgolf() const;
};