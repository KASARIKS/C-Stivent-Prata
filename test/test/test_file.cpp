#include "test_header.h"
namespace test_library {
	void A::PrintSpecial() 
	{
		std::cout << value << std::endl;
	}

	void B::PrintSpecial()
	{
		std::cout << GetValue() + salt << std::endl;
	}
}