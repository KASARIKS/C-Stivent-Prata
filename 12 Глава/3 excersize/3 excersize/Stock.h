#pragma once
#include <iostream>

class Stock
{
private:
	static const int NAMELEN = 30;
	char* company;
	int shares;
	double share_val, total_val;
	void set_tot() { total_val = shares * share_val; }
public:
	Stock();
	Stock(const char* co, int n = 0, double pr = 0.0);
	Stock(const Stock& obj);
	~Stock();
	void buy(int num, double price);
	void sell(int num, double price);
	void update(double price);
	Stock& operator=(const Stock& obj);
	friend std::ostream& operator<<(std::ostream& os, const Stock& obj);
	const Stock& topval(const Stock& s) const;
};