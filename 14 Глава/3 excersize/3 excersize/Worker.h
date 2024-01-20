#pragma once
#include <string>

static int count = 0;

class Worker
{
public:
	std::string fullname;
	long id;

	Worker() : fullname("no one"), id(++count) {}
};