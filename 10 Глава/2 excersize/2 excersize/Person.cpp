#include "Person.h"

Person::Person(const std::string& ln, const char* fn) {
	this->lname = ln;
	strcpy_s(this->fname, this->LIMIT, fn);
}

void Person::Show() const {
	std::cout << this->fname << ", " << this->lname << std::endl;
}

void Person::FormalShow() const {
	std::cout << this->lname << ", " << this->fname << std::endl;
}