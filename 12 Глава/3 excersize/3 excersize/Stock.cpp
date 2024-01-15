#include "Stock.h"

Stock::Stock()
{
	company = new char[NAMELEN];
	strcpy_s(company, NAMELEN - 1, "without name");
	shares = 0;
	share_val = total_val = 0.0;
}

Stock::Stock(const char* co, int n, double pr)
{
	company = new char[NAMELEN];
	strncpy_s(company, NAMELEN - 1, co, NAMELEN - 1);
	company[NAMELEN - 1] = '\0';
	if (n < 0)
	{
		std::cerr << "Package number cannot be negative; for "
			<< company << " setted in zero.\n";
		shares = 0;
	}
	else 
		shares = n;
	share_val = pr;
	set_tot();
}

Stock::Stock(const Stock& obj)
{
	delete[] company;
	company = new char[NAMELEN];
	strncpy_s(company, NAMELEN - 1, obj.company, NAMELEN - 1);
	shares = obj.shares;
	share_val = obj.share_val;
	total_val = obj.total_val;
}

Stock::~Stock()
{
	delete[] company;
}

void Stock::buy(int num, double price)
{
	if (num < 0)
	{
		std::cerr << "The number of purchased packages cannot be negaive."
			<< " The transaction was aborted.\n";
	}
	else
	{
		shares += num;
		share_val = price;
		set_tot();
	}
}

void Stock::sell(int num, double price)
{
	using std::cerr;
	if (num < 0)
	{
		std::cerr << "The number of selled packages cannot be negaive."
			<< " The transaction was aborted.\n";
	}
	else if (num > shares)
	{
		std::cerr << "You can't sell more than you have! "
			<< " The transaction was aborted.\n";
	}
	else
	{
		shares -= num;
		share_val = price;
		set_tot();
	}
}

void Stock::update(double price)
{
	share_val = price;
	set_tot();;
}

Stock& Stock::operator=(const Stock& obj)
{
	if (this == &obj)
		return *this;
	delete[] company;
   	company = new char[NAMELEN];
	strncpy_s(company, NAMELEN - 1, obj.company, NAMELEN - 1);
	shares = obj.shares;
	share_val = obj.share_val;
	total_val = obj.total_val;
	return *this;
}

std::ostream& operator<<(std::ostream& os, const Stock& obj)
{
	os << "Company: " << obj.company
		<< "Packages: " << obj.shares << std::endl
		<< "Package price: $" << obj.share_val
		<< "Total price: $" << obj.total_val << std::endl;
	return os;
}

const Stock& Stock::topval(const Stock& s) const
{
	if (s.total_val > total_val)
		return s;
	else return *this;
}