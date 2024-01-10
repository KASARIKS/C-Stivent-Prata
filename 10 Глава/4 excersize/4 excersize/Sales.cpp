#include "Sales.h"
#include <iostream>

using namespace SALES;

void Sales::SetSales(const double ar[], int n) {
	int tmp_n = n < 4 ? 4 : n;
	double sum = 0;
	max = ar[0], min = ar[0];
	for (int i = 0; i < tmp_n; ++i) {
		sales[i] = ar[i];
		sum += ar[i];
		if (max < ar[i]) max = ar[i];
		if (min > ar[i]) min = ar[i];
	}
	average = sum / tmp_n;
}

// User input and set for n = 4
Sales::Sales() {
	const int tmp_n = 4;
	double tmp_sales[tmp_n];
	for (int i = 0; i < tmp_n; ++i) {
		std::cout << "Input sale " << i + 1 << ": ";
		std::cin >> tmp_sales[i];
	}
	SetSales(tmp_sales, tmp_n);
}

void Sales::ShowSales() const {
	std::cout << "Average: " << average << std::endl;
	std::cout << "Max: " << max << std::endl;
	std::cout << "Min: " << min << std::endl;
}