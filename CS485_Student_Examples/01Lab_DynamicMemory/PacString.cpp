#include "PacString.h"

PacString::PacString()
{
}

PacString::PacString(const char * pszString)
{
	mpszData = new char [strlen(pszString) + 1];

	strcpy_s(mpszData, strlen(pszString) + 1, pszString);	
}

PacString::PacString(const PacString & rcData)
{
	mpszData = rcData.mpszData;
}

PacString::~PacString()
{
	delete mpszData;
}

PacString & PacString::operator=(PacString rcData)
{
	using std::swap;
	swap (mpszData, rcData.mpszData);

	return *this;
}
/*
PacString & PacString::operator+=(const PacString & rcData)
{
	// TODO: insert return statement here
	
}
*/
PacString PacString::operator+(const PacString & rcData) const
{
	strncat (mpszData, rcData.mpszData, (strlen(rcData.mpszData) + strlen(mpszData)) + 1);

	return *this;
}

std::ostream & operator<<(std::ostream & out, const PacString & rcData)
{
	out << rcData.mpszData;
 	return out;
}
