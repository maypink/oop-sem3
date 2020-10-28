#include "ParsedFile.h"

void ParsedINIFile::AddSection(const std::string& sectionName, const std::map<std::string, std::string>& keys)
{
	data.insert(make_pair(sectionName, keys));
}

std::string ParsedINIFile::GetData(const std::string& section, const std::string& key)
{

	if (data[section].find(key) == data[section].end())
		throw KeysError();

	return data[section][key];
}
