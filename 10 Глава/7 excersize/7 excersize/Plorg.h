#pragma once
#include <iostream>
namespace PLORG {
	class Plorg {
	private:
		static const int MAXLEN = 19;
		std::string name;
		int ci;
	public:
		Plorg(std::string name = "Plorg", int ci = 50);
		void SetCI(int ci);
		void SayInfo() const;
	};
}