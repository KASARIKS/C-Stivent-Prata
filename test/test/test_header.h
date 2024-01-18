#pragma once
#include <iostream>
namespace test_library {
	class A
	{
	private:
		int value;
	public:
		A(int value = 10) { this->value = value; }
		virtual void PrintSpecial();
		int GetValue() { return value; }
	};

	class B : public A
	{
	private:
		int salt;
	public:
		B(int value = 10, int salt = 2) : A(value) { this->salt = salt; }
		virtual void PrintSpecial();
	};
}