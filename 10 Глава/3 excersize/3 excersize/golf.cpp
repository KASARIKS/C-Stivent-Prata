#include "golf.h"
#include <iostream>
#include <string>

void golf::setgolf(const char* name, int hc) {
	strcpy_s(m_fullname, LEN, name);
	m_handicap = hc;
}

int golf::setgolf() {
	std::cout << "Input fullname: ";
	std::cin >> m_fullname;
	std::cout << "Input number of handicaps: ";
	std::cin >> m_handicap;
	return m_fullname != "";
}

void golf::handicap(int hc) {
	m_handicap = hc;
}

void golf::showgolf() const {
	std::cout << "Fullname: " << m_fullname << std::endl;
	std::cout << "Handicaps: " << m_handicap << std::endl;
}