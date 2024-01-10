// Modification of random walk
#include <iostream>
#include "vect.h"
#include <vector>
#include <algorithm>
#include <numeric>

int main()
{
	srand(time(0));
	double direction;
	VECTOR::Vector step, result(0.0, 0.0);
	unsigned long int steps = 0;
	double target, dstep;
	int atemtps_number;
	std::cout << "Input distance (q for exit): ";
	while (std::cin >> target)
	{
		std::cout << "Input number of atempts: ";
		if (!(std::cin >> atemtps_number))
			break;

		std::cout << "Input length of step: ";
		if (!(std::cin >> dstep))
			break;

		// Count attempts
		std::vector<unsigned long int> all_steps;

		for (int i = 0; i < atemtps_number; ++i) {
			while (result.magval() < target)
			{
				direction = rand() % 360;
				step.set(dstep, direction, 'p');
				result = result + step;
				steps++;
			}
			all_steps.push_back(steps);
			steps = 0;
			result.set(0.0, 0.0);
		}

		std::cout << "Max step: " << *std::max_element(all_steps.begin(), all_steps.end()) << std::endl;
		std::cout << "Min step: " << *std::min_element(all_steps.begin(), all_steps.end()) << std::endl;
		std::cout << "Average step: " << std::reduce(all_steps.begin(), all_steps.end(), 0) / all_steps.size() << std::endl;

		std::cout << "Input distance (q for exit): ";
	}
	std::cout << "Don't abuse!" << std::endl;
	return 0;
}