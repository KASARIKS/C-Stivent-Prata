#pragma once
template <class Type>

class Stack
{
private:
	enum { SIZE = 10 };
	int stacksize;
	Type* items;
	int top;
};