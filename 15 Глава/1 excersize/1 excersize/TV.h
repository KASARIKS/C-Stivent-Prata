#pragma once
#include <iostream>

class Remote;
class Tv
{
	friend class Remote;
private:
	int state;
	int volume;
	int maxchannel, channel;
	int mode;
	int input;
public:
	void buzz(Remote& r);
	enum Stat{Off, On};
	enum {MinVal, MaxVal = 20};
	enum{Antenna, Cable};
	enum {TV, VCR};
	Tv(int s = Off, int mc = 100) : state(s), volume(5), maxchannel(mc),
	channel(2), mode(Cable), input(TV) {}
	void onoff() { state = (state == On) ? Off : On; }
	bool ison() const { return state == On; }
	bool volup();
	bool voldown();
	void chanup();
	void chandown();
	void set_mode() { mode = (mode == Antenna) ? Cable : Antenna; }
	void set_input() { input = (input == TV) ? VCR : TV; }
	void settings() const;		
};

class Remote
{
	friend class Tv;
private:
	int mode;
	int buzz_mode;
public:
	Remote() : buzz_mode(0) {};
	bool volup(Tv& t) { return t.volup(); }
	void onoff(Tv& t) { return t.onoff(); }
	bool ison(Tv& t) const { return t.ison(); }
	bool voldown(Tv& t) { return t.voldown(); }
	void chanup(Tv& t) { return t.chanup(); }
	void chandown(Tv& t) { return t.chandown(); }
	void set_mode(Tv& t) { return t.set_mode(); }
	void set_input(Tv& t) { return t.set_input(); }
	void buzz(Tv& t);
	void show() { std::cout << "Mode: " << buzz_mode << std::endl; }
};