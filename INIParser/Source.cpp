#include <iostream>
#include <algorithm>
#include <string>
#include "INIParser.h"
#include "Types.h"

int main(int argc, const char** argv)
{
	if (argc != 2) {

		std::cerr << "Wrong number of parameters, try again";
		return 1;

	}

	ParsedINIFile iniFile;

	try {

		iniFile = INIParser().Parse(argv);

	}
	catch (TextError & ex) {

		std::cerr << ex.what() << '\n';

	}
	catch (std::exception & ex) {

		std::cerr << ex.what() << '\n';
		return 1;

	}

	std::string section, param;
	int type;

	std::cout << "Enter the section:\n";
	std::cin >> section;
	std::cout << "\nEnter the parameter:\n";
	std::cin >> param;
	std::cout << "\nSpecify the type in which you would like to see the values. \nYou can choose between \n1 - 'int', \n2 - 'float' \n3 - 'string'\n";
	std::cin >> type;

	try {

		switch (type) {

		case INTEGER:
		{

			int valInt = 0;
			valInt = std::stoi(iniFile.GetData(section, param));
			std::cout << "Section: " << section << '\n' << "Parameter: " << param << '\n' << "Int value: " << valInt;
			break;
		}
		case FLOAT:
		{
			float valFloat = 0.0f;
			valFloat = std::stof(iniFile.GetData(section, param));
			std::cout << "Section: " << section << '\n' << "Parameter: " << param << '\n' << "Float value: " << valFloat;
			break;
		}
		case STRING:
		{
			std::string valString = "";
			valString = iniFile.GetData(section, param);
			std::cout << "Section: " << section << '\n' << "Parameter: " << param << '\n' << "String value: " << valString;
			break;
		}
		default:
		{
			std::cerr << "Wrong type, you can use only 'int', 'float' and 'string'";
			return 2;
		}
		}
	}
	catch (const KeysError & ex) {
		std::cerr << ex.what() << '\n';
	}
	catch (std::exception & ex) {
		std::cerr << ex.what() << '\n';
	}
}