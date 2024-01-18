#include "DMA.h"

namespace DMA
{
	// Abstarct methods
	AbstractDMA::AbstractDMA(const char* l, int r)
	{
		label = new char[strlen(l) + 1];
		strcpy_s(label, strlen(l) + 1, l);
		rating = r;
	}

	AbstractDMA::AbstractDMA(const AbstractDMA& rt)
	{
		label = new char[strlen(rt.label) + 1];
		strcpy_s(label, strlen(rt.label) + 1, rt.label);
		rating = rt.rating;
	}

	// Basic methods
	baseDMA::baseDMA(const char* l, int r) : AbstractDMA(l, r)
	{
		
	}

	baseDMA::baseDMA(const baseDMA& rt) : AbstractDMA(rt)
	{
	
	}

	baseDMA& baseDMA::operator=(const baseDMA& rt)
	{
		if (this != &rt)
		{
			delete[] label;
			label = new char[strlen(rt.label) + 1];
			strcpy_s(label, strlen(rt.label), rt.label);
			rating = rt.rating;
		}
		return *this;
	}

	std::ostream& operator<<(std::ostream& os, const baseDMA& rt)
	{
		os << "Name: " << rt.label << std::endl;
		os << "Rating: " << rt.rating << std::endl;
		return os;
	}

	// Lacks methods
	lacksDMA::lacksDMA(const char* c, const char* l, int r) : AbstractDMA(l, r)
	{
		strncpy_s(color, 39, c, 39);
		color[39] = '\0';
	}

	lacksDMA::lacksDMA(const char* c, const AbstractDMA& rs) : AbstractDMA(rs)
	{
		strncpy_s(color, COL_LEN - 1, c, COL_LEN - 1);
		color[COL_LEN - 1] = '\0';
	}
	
	std::ostream& operator<<(std::ostream& os, const lacksDMA rs)
	{
		os << (const baseDMA&)rs;
		os << "Color: " << rs.color << std::endl;
		return os;
	}

	// Has methods
	hasDMA::hasDMA(const char* s, const char* l, int r) : AbstractDMA(l, r)
	{
		style = new char[strlen(s) + 1];
		strcpy_s(style, strlen(s) + 1, s);
	}

	hasDMA::hasDMA(const hasDMA& hs) : AbstractDMA(hs)
	{
		style = new char[strlen(hs.style) + 1];
		strcpy_s(style, strlen(hs.style) + 1, hs.style);
	}

	hasDMA::~hasDMA()
	{
		delete[] style;
	}

	hasDMA& hasDMA::operator=(const hasDMA& hs)
	{
		if (this != &hs)
		{
			delete[] label;
			label = new char[strlen(hs.label) + 1];
			strcpy_s(label, strlen(hs.label) + 1, hs.label);
			rating = hs.rating;
			style = new char[strlen(hs.style) + 1];
			strcpy_s(style, strlen(hs.style) + 1, hs.style);
		}
		return *this;
	}

	std::ostream& operator<<(std::ostream& os, const hasDMA& hs)
	{
		os << (const baseDMA&)hs;
		os << "Style: " << hs.style << std::endl;
		return os;
	}

}