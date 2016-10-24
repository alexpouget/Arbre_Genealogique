#pragma once
#include <string>
class Member
{
public:
	Member(std::string firstName, std::string lastName, int yearOfBirth, std::string eyesColor);
	Member();
	~Member();

	std::string getFirstName();
	std::string getEyesColor();
	int getAge();

private:
	std::string firstName;
	std::string lastName;
	int yearOfBirth;
	std::string eyesColor;
};

