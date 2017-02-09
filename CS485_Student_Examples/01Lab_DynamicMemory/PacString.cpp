#include "PacString.h"

PacString::PacString()
{
}

PacString::PacString(const char * pszString)
{
	// ctor
	//using std::copy;
	//*mpszData = *pszString;
	//new char * temp;// = pszString;



	
}

PacString::PacString(const PacString & rcData)
{
	// copy ctor
}

PacString::~PacString()
{
}
/*
PacString & PacString::operator=(PacString rcData)
{
	// TODO: insert return statement here
}

PacString & PacString::operator+=(const PacString & rcData)
{
	// TODO: insert return statement here
	
}

PacString PacString::operator+(const PacString & rcData) const
{
	return PacString();
}*/

std::ostream & operator<<(std::ostream & out, const PacString & rcData)
{
	// TODO: insert return statement here
	return out;
}
