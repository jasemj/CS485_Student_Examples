#include "PacString.h"

PacString::PacString()
{
}

PacString::PacString(const char * pszString)
{

	mpszData = new char [strlen(pszString) + 1];

	for (int i = 0; i < strlen(pszString) + 1; i++)
	{
		mpszData[i] = pszString[i];
	}
}

PacString::PacString(const PacString & rcData)
{
	mpszData = new char[strlen(rcData.mpszData) + 1];

	for (int i = 0; i < strlen(rcData.mpszData) + 1; i++)
	{
		mpszData[i] = rcData.mpszData[i];
	}
}

PacString::~PacString()
{
	
	if (mpszData != nullptr)
	{
		cout << "dtor " << mpszData << endl;
		delete[] mpszData;
	}
	
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
	int count = 0;
	int size = strlen(mpszData) + strlen(rcData.mpszData) + 1;
	char * temp = new char[size];
	PacString tempString (temp);

	for (int i = 0; i < size; i++)
	{
		if (i < strlen(mpszData))
		{
			temp[i] = mpszData[i];
		}
		else
		{
			temp[i] = rcData.mpszData[count];
			count++;
		}
	}

	delete[] temp;
	return tempString;
}

std::ostream & operator<<(std::ostream & out, const PacString & rcData)
{
	out << rcData.mpszData;
 	return out;
}
