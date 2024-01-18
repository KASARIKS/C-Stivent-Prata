#include <iostream>
#include "test_header.h"

int main(void) {
	using namespace test_library;

	test_library::A first(11);
	first.PrintSpecial();
	test_library::B second(11, 3);
	second.PrintSpecial();

	std::cout << std::endl;
	std::cout << "Loop of A and B classes:" << std::endl;
	
	// Polimorphism
	test_library::A *test_classes[4] = { new A(12), new B(12, 2), new A(13), new B(13, 3)};
	for (int i = 0; i < 4; ++i)
		test_classes[i]->PrintSpecial();

	// Free memory
	for (int i = 0; i < 4; ++i)
		delete test_classes[i];

	return 0;
}