#pragma once
#include <stdexcept>
#include <cstring>
class Sales
{
public:
	enum {MONTHS = 12};
	class bad_index : public std::logic_error
	{
	private:
		int bi;
	public:
		explicit bad_index(int ix, const char* s = "Error of index in object Sales\n");
		int bi_val() const { return bi; }
	};

	explicit Sales(int yy = 0);
	Sales(int yy, const double* gr, int n);
	virtual ~Sales() {}
	int Year() const { return year; }
	virtual double operator[](int i) const throw(std::logic_error);
	virtual double& operator[](int i) throw(std::logic_error);
private:
	double gross[MONTHS];
	int year;
};

class LabeledSales : public Sales
{
public:
	static const int STRLEN = 50;
	class nbad_index : public Sales::bad_index
	{
	private:
		char lbl[STRLEN];
	public:
		nbad_index(const char* lb, int ix, 
			const char* s = "Error of index in object LabeledSales\n");
		const char* label_val() { return lbl; }
	};
	explicit LabeledSales(const char* lb = "none", int yy = 0);
	LabeledSales(const char* lb, int yy, const double* gr, int n);
	virtual ~LabeledSales() {}
	const char* Label() const { return label; }
	virtual double operator[](int i) const throw(std::logic_error);
	virtual double& operator[](int i) throw(std::logic_error);
private:
	char label[STRLEN];
};