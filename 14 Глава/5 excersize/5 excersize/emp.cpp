#include "emp.h"
#include <iostream>

// abstr_emp methods
abstr_emp::abstr_emp() : fname(""), lname(""), job("")
{
}

abstr_emp::abstr_emp(const std::string& fn, const std::string& ln, const std::string& j)
{
	fname = fn;
	lname = ln;
	job = j;
}

void abstr_emp::ShowAll() const
{
	std::cout << "First and last name, job: ";
	std::cout << *this << std::endl;
}

void abstr_emp::SetAll()
{
	fname = lname = job = "";
}

std::ostream& operator<<(std::ostream& os, const abstr_emp& e)
{
	os << e.fname << ", " << e.lname << ", " << e.job;
	return os;
}

// employee methods

employee::employee() : abstr_emp()
{
}

employee::employee(const std::string& fn, const std::string& ln, const std::string& j)
	: abstr_emp(fn, ln, j)
{
}

void employee::ShowAll() const
{
	std::cout << "First and last name, job: ";
	std::cout << *this << std::endl;
}

void employee::SetAll()
{
	abstr_emp::SetAll();
}

// manager methods
manager::manager() : abstr_emp()
{
	inchargeof = 0;
}

manager::manager(const std::string& fn, const std::string& ln, 
	const std::string& j, int ico) : abstr_emp(fn, ln, j)
{
	inchargeof = ico;
}

manager::manager(const abstr_emp& e, int ico) : abstr_emp(e)
{
	inchargeof = ico;
}

manager::manager(const manager& m) : abstr_emp(m)
{
	inchargeof = m.inchargeof;
}

void manager::ShowAll() const
{
	abstr_emp::ShowAll();
	std::cout << "Incharge of: ";
	std::cout << inchargeof << std::endl;
}

void manager::SetAll()
{
	abstr_emp::SetAll();
	inchargeof = 0;
}

// fink methods
fink::fink() : abstr_emp()
{
	reportsto = "";
}

fink::fink(const std::string& fn, const std::string& ln, 
	const std::string& j, const std::string& rpo) : abstr_emp(fn, ln, j)
{
	reportsto = rpo;
}

fink::fink(const abstr_emp& e, const std::string& rpo) : abstr_emp(e)
{
	reportsto = rpo;
}

fink::fink(const fink& e) : abstr_emp(e)
{
	reportsto = e.reportsto;
}

void fink::ShowAll() const
{
	abstr_emp::ShowAll();
	std::cout << "Reports to: ";
	std::cout << reportsto << std::endl;;
}

void fink::SetAll()
{
	abstr_emp::SetAll();
	reportsto = "";
}

// highfink methods
highfink::highfink() : abstr_emp(), manager(), fink()
{
}

highfink::highfink(const std::string& fn, const std::string& ln, 
	const std::string& j, const std::string& rpo, int ico)
	: abstr_emp(fn, ln, j), manager(fn, ln, j, ico), fink(fn, ln, j, rpo)
{
}

highfink::highfink(const abstr_emp& e, const std::string& rpo, int ico)
	: abstr_emp(e), manager(e, ico), fink(e, rpo)
{
}

highfink::highfink(const fink& f, int ico)
	: abstr_emp(f), manager((const manager&)f, ico), fink(f)
{
}

highfink::highfink(const manager& m, const std::string& rpo)
	: abstr_emp(m), manager(m), fink((const fink&)m, rpo)
{
}

highfink::highfink(const highfink& h)
	: abstr_emp(h), manager((const manager&)h), fink((const fink&)h)
{
}

void highfink::ShowAll() const
{
	abstr_emp::ShowAll();
	std::cout << "In charge of: " << manager::InChargeOf() << std::endl;
	std::cout << "Reports to: " << fink::ReportsTo() << std::endl;
}

void highfink::SetAll()
{
	abstr_emp::SetAll();
	manager::InChargeOf() = 0;
	fink::ReportsTo() = "";
}

