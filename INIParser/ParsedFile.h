#pragma once
#include <map>
#include <string>
#include "Exceptions.h"

class ParsedINIFile
{
	std::map<std::string, std::map<std::string, std::string>> data;

public:

	ParsedINIFile() {}

	void AddSection(const std::string& sectionName, const std::map<std::string, std::string>& keys);

	std::string GetData(const std::string& section, const std::string& key);

};