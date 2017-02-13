//***************************************************************************
// File name:  PacString.cpp
// Author:     Jasem Jaihouni and Joshua Napoles
// Date:       2/9/2017
// Class:      CS485
// Assignment: Dynamic Memory Lab
// Purpose:    Practice using raw pointers
//***************************************************************************
#include "PacString.h"

//***************************************************************************
// Constructor: PacString
//
// Description: Defualt constructor
//
// Parameters:  None
//
// Returned:    None
//***************************************************************************

PacString::PacString()
{
	cout << "ctor(def)" << endl;
}

//***************************************************************************
// Constructor: PacString
//
// Description: Sets mpszData to the string passed in.
//
// Parameters:  pszString - the string to set to mpszData
//
// Returned:    None
//***************************************************************************

PacString::PacString(const char * pszString)
{

	mpszData = new char [strlen(pszString) + 1];
	cout << "cctor*" << endl;
	for (int i = 0; i < strlen(pszString) + 1; i++)
	{
		mpszData[i] = pszString[i];
	}
}

//***************************************************************************
// Constructor: PacString
//
// Description: Sets mpszData to the string inside of the rcData object.
//
// Parameters:  rcData - the object containing the string
//
// Returned:    None
//***************************************************************************

PacString::PacString(const PacString & rcData)
{
	mpszData = new char[strlen(rcData.mpszData) + 1];
	cout << "cctor&" << endl;
	for (int i = 0; i < strlen(rcData.mpszData) + 1; i++)
	{
		mpszData[i] = rcData.mpszData[i];
	}
}

//***************************************************************************
// Destrcutor:  ~PacString
//
// Description: Deletes the dynamic memory
//
// Parameters:  None
//
// Returned:    None
//***************************************************************************

PacString::~PacString()
{
	
	if (mpszData != nullptr)
	{
		cout << "dtor " << mpszData << endl;
		delete[] mpszData;
	}
	
}

//***************************************************************************
// Function:    operator=
//
// Description: Sets mpszData to the paramater objects mpszData. 
//
// Parameters:  rcData - the object to copy the data from
//
// Returned:    The object operator= is called to return the object
//***************************************************************************

PacString & PacString::operator=(const PacString & rcData)
{
	
	delete[] mpszData;
	int size = strlen (rcData.mpszData) + 1;
	char * temp = new char[size];
	
	for (int i = 0; i < size; i++)
	{
		temp[i] = rcData.mpszData[i];
	}

	mpszData = temp;

	return *this;
}


//***************************************************************************
// Function:    operator=
//
// Description: Sets mpszData to the paramater objects mpszData.
//
// Parameters:  rcData - the object to copy the data from
//
// Returned:    The object operator= is called to return the object
//***************************************************************************
/*
PacString & PacString::operator=(PacString rcData)
{
	using std::swap;
	swap (mpszData, rcData.mpszData);

	return *this;
}*/

//PacString & PacString::operator+=(const PacString & rcData)
//{
	
	
	/*int size = strlen(mpszData) + strlen(rcData.mpszData) + 1;
	char * temp = new char[size];

	temp = mpszData + rcData.mpszData;

	delete[] mpszData;

	mpszData = temp;

	return *this;*/
//}

//***************************************************************************
// Function:    operator+
//
// Description: Add the paramater objects mpszData to our mpszData 
//
// Parameters:  rcData - the object to add the data from
//
// Returned:    The object operator= is called to return the object
//***************************************************************************

PacString PacString::operator+(const PacString & rcData) const
{
	int count = 0;
	int size = strlen(mpszData) + strlen(rcData.mpszData) + 1;
	char * temp = new char[size];
	
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

	PacString tempString (temp);
	delete[] temp;
	return tempString;
}
//***************************************************************************
// Function:    operator<<
//
// Description: Displays the data to the screen from our object 
//
// Parameters:  out - the ostream object to display to
//				rcData - the object to display the data from
//
// Returned:    The ostream object
//***************************************************************************

std::ostream & operator<<(std::ostream & out, const PacString & rcData)
{
	out << rcData.mpszData;
 	return out;
}
