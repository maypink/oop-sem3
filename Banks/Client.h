#pragma once
#include <string>
#include <iostream>

class Client {

private:

	std::string name;
	
	std::string surname;

	std::string address;

	std::string passport;

public:

	Client();

	std::string GetName();

	std::string GetSurname();

	std::string GetAddress();

	std::string GetPassport();

};