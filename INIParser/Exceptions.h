#pragma once
#include <exception>

class KeysError :
	public std::exception
{
public:
	const char* what() const {
		return "There is no such combination of section and parameter";
	}
};

class InpError :
	public std::exception
{
public:
	const char* what() const {
		return "File was not open";
	}
};

class TextError :
	public std::exception
{
public:
	const char* what() const {

		return "Wrong symbol in the file";

	}
};
#pragma once
