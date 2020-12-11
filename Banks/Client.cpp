#include "Client.h"

Client::Client() { 

	std::cout << "Enter the name:\n";

	std::string name, surname, address, passport;

	std::cin >> name;

	this->name = name;

	std::cout << "Enter the surname:\n";

	std::cin >> surname;

	this->surname = surname;

	std::cout << "Enter the address:\n";

	std::cin >> address;

	this->address = address;

	std::cout << "Enter the passport data:\n";

	std::cin >> passport;

	this->passport = passport;

}

std::string Client::GetName() {

	return this->name;

}

std::string Client::GetSurname() {

	return this->surname;

}

std::string Client::GetAddress() {

	return this->address;

}

std::string Client::GetPassport() {

	return this->passport;

}