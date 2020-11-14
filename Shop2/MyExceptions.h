#pragma once
#include <exception>
#include <string.h>

class GetParamError : public std::exception {

public: 

	GetParamError() = default;

	const char* what() const noexcept override {
		return "Wrong value: value out of permissible range";
	}

};

class AvailabilityError : public std::exception {

public:

	AvailabilityError() = default;

	const char* what() const noexcept override {
		return "There are no enough products or no such product at all";
	}

};

class UniqueIDError : public std::exception {

public:

	UniqueIDError() = default;

	const char* what() const noexcept override {
		return "All identifiers should be unique, you entered not unique";
	}

};