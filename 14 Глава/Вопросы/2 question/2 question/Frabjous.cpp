#include "Frabjous.h"

Frabjous::Frabjous(const char* s)
{
	strcpy_s(fab, 20, s);
}

Gloam::Gloam(int g, const char* s) : fb(s)
{
	glip = g;
}

Gloam::Gloam(int g, const Frabjous& f) : fb(f)
{
	glip = g;
}

void Gloam::tell()
{
	cout << glip << ", ";
	fb.tell();
}
