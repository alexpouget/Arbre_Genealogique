#include "Member.h"



Member::Member(std::string firstName, std::string lastName, int yearOfBirth, std::string eyesColor)
{
	this->firstName = firstName;
	this->lastName = lastName;
	this->yearOfBirth = yearOfBirth;
	this->eyesColor = eyesColor;
}

Member::Member()
{
}


Member::~Member()
{
}

std::string Member::getFirstName()
{
	return this->firstName;
}

std::string Member::getEyesColor()
{
	return eyesColor;
}

int Member::getAge()
{
	return 2016-yearOfBirth;
}
