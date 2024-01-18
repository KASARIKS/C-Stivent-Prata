#pragma once
#include <iostream>
namespace DMA
{
	class AbstractDMA
	{
	protected:
		char* label;
		int rating;
	public:
		AbstractDMA(const char* l = "null", int r = 0);
		AbstractDMA(const AbstractDMA& rt);
		virtual ~AbstractDMA() = 0
		{
			delete[] label;
		}
	};

	class baseDMA : public AbstractDMA
	{
	public:
		baseDMA(const char* l = "null", int r = 0);
		baseDMA(const baseDMA& rt);

		baseDMA& operator=(const baseDMA& rt);
		
		friend std::ostream& operator<<(std::ostream& os, const baseDMA& rt);
	};

	class lacksDMA : public AbstractDMA
	{
	private:
		enum { COL_LEN = 40 };
		char color[COL_LEN];
	public:
		lacksDMA(const char* c = "blank", const char* l = "null", int r = 0);
		lacksDMA(const char* c, const AbstractDMA& rs);
		friend std::ostream& operator<<(std::ostream& os, const lacksDMA rs);
	};

	class hasDMA : public AbstractDMA
	{
	private:
		char* style;
	public:
		hasDMA(const char* s = "none", const char* l = "null", int r = 0);
		hasDMA(const hasDMA& hs);
		~hasDMA();
		hasDMA& operator=(const hasDMA& hs);
		friend std::ostream& operator<<(std::ostream& os, const hasDMA& hs);
	};
}