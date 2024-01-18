#pragma once

class Cd
{
private:
	char *performers;
	char *label;
	int selections;
	double playtime;
public:
	Cd(const char* s1, const char* s2, int n, double x);
	Cd(const Cd& d);
	Cd();
	~Cd();
	virtual void Report() const; // Print all data
	Cd& operator=(const Cd& d);
};

class Clasic : public Cd
{
protected:
	char *favorite_composition;
public:
	virtual void Report() const; // Print all data

	Clasic(const char* s1, const char* s2, const char* s3, int n, double x);
	Clasic(const Clasic& d);
	Clasic();
	~Clasic();
	Clasic& operator=(const Clasic& d);
};