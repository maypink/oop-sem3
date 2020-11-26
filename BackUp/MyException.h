#pragma once

#include <exception>

class GetParamError : public std::exception {

public:

	GetParamError() = default;

	const char* what() const noexcept override {
		return "Wrong value: value out of permissible range";
	}

};

class IncrementPointError : public std::exception {

public:

	IncrementPointError() = default;

	const char* what() const noexcept override {
		return "Something is wrong with increment point";
	}

};

class ExistenceError : public std::exception {

public:

	ExistenceError() = default;

	const char* what() const noexcept override {
		return "You are trying to perform an action on a non-existent object";
	}

};
