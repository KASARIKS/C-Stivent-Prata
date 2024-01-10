#pragma once
#include <iostream>
// Vector class with operations
namespace VECTOR
{
	class Vector
	{
	private:
		// X, Y move and angular with length
		double x, y, mag, ang;
		char mode;
		// Setters
		void set_mag();
		void set_ang();
		void set_x();
		void set_y();
	public:
		explicit Vector();
		explicit Vector(double n1, double n2, char form = 'r');
		void set(double n1, double n2, char form = 'r');

		// Getters
		double xval() const { return x; }
		double yval() const { return y; }
		double magval() const { return mag; }
		double angval() const { return ang; }

		// Set modes
		void polar_mode() { mode = 'p'; }
		void rect_mode() { mode = 'r'; }

		// Operation overloadings
		Vector operator+(const Vector& b) const;
		Vector operator-(const Vector& b) const;
		Vector operator-() const;
		Vector operator*(double n) const;

		// Friends(also operation overloadings)
		friend Vector operator*(double n, const Vector& a);
		friend std::ostream& operator<<(std::ostream& os, const Vector& v);
	};
}