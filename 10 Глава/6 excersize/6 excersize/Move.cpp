#include "Move.h"
#include <iostream>

Move::Move(double a, double b) {
	x = a, y = b;
}

Move Move::add(const Move& m) const {
	return Move(m.x, m.y);
}

void Move::showmove() const {
	std::cout << "Cords: " << x << " " << y << std::endl;
}

void Move::reset(double a, double b) {
	x = a, y = b;
}