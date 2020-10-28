#pragma once
#include <fstream>
#include <string>
#include <regex>
#include <iostream>
#include <cctype>
#include <string.h>
#include "ParsedFile.h"
#include "Exceptions.h"

class INIParser
{
public:

	ParsedINIFile Parse(const char** filePath);

};