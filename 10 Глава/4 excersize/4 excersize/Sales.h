#pragma once
namespace SALES {
	class Sales {
	private:
		static const int QUARTERS = 4;
		double sales[QUARTERS];
		double average, max, min;
	public:
		void SetSales(const double ar[], int n);
		Sales();
		void ShowSales() const;
	};
}