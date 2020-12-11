#pragma once
#include <exception>

class ExcessError : public std::exception {

public:

	ExcessError() = default;

	const char* what() const noexcept override {

		return "Some limit has been exceeded";
	
	}

};

class ExistenceError : public std::exception {

public:

	ExistenceError() = default;

	const char* what() const noexcept override {

		return "No such object exists or you are trying to create object that is already exists";

	}

};