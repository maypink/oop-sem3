#pragma once
#include <exception>

class GetParamError : public std::exception {

public:

	GetParamError() = default;

	const char* what() const noexcept override {
		return "Wrong value: value out of permissible range";
	}

};

class EmptyRaceError : public std::exception {

public:

	EmptyRaceError() = default;

	const char* what() const noexcept override {
		return "Current race is empty, add some vehicles";
	}

};