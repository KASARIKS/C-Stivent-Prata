// Modification of random walk
#include <iostream>
#include "vect.h"
#include <fstream>

int main()
{
	const std::string file_name = "moves_info.txt";
	std::ofstream moves_info(file_name);
	srand(time(0));
	double direction;
	VECTOR::Vector step, result(0.0, 0.0);
	unsigned long int steps = 0;
	double target, dstep;
	std::cout << "Input distance (q for exit): ";
	while (std::cin >> target)
	{
		std::cout << "Input length of step: ";
		if (!(std::cin >> dstep))
			break;

		moves_info << "Target distance: " << target << ", Step size: " << dstep << "\n";

		while (result.magval() < target)
		{
			direction = rand() % 360;
			step.set(dstep, direction, 'p');
			result = result + step;
			moves_info << steps << ": " << result << "\n";
			steps++;
		}
		std::cout << "After " << steps << " steps object has next cords: " << std::endl;
		moves_info << "After " << steps << " steps object has next cords: " << "\n";
		std::cout << result << std::endl;
		moves_info << result << "\n";
		result.polar_mode();
		std::cout << " or\n" << result << std::endl;
		moves_info << " or\n" << result << "\n";
		std::cout << "Average distance on 1 step = " << result.magval() / steps << std::endl;
		moves_info << "Average distance on 1 step = " << result.magval() / steps << "\n";
		steps = 0;
		result.set(0.0, 0.0);
		std::cout << "Input distance (q for exit): ";
	}
	std::cout << "Don't abuse!" << std::endl;
	return 0;
}