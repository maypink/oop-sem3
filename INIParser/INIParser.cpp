#include "INIParser.h"

ParsedINIFile INIParser::Parse(const char** path)
{

	std::ifstream input(path[1], std::ios_base::binary);

	if (!input.is_open()) {
		throw InpError();
	}

	ParsedINIFile builder;

	std::string cur;

	std::string section;
	std::map<std::string, std::string> keys;
	std::string param;

	std::regex letters_("[0-9A-Z_]+");
	std::regex keysRE("\\s*[[:w:]_]+\\s*=\\s*[[:w:]/\\.]+\\s*(;.*)?");

	bool flag = 0;
	short int comm = 0;
	std::string bufSection = "";
	std::string buffer;

	while (!input.eof()) {

		getline(input, cur);
		if (std::regex_match(cur, keysRE)) {

			auto it = cur.begin();

			while (!isspace(*it)) {
				it++;
			}

			param = cur.substr(std::distance(cur.begin(), cur.begin()), std::distance(cur.begin(), it));

			keys[param] = cur.substr(std::distance(cur.begin(), it + 3), std::distance(cur.begin(), cur.end() - 1));

		}
		else if (cur == "")
		{
			continue;
		}
		else {
			auto it = cur.begin();
			switch (*it) {
			case '[':
				if (section != "")
				{
					builder.AddSection(section, keys);
					keys.clear();
				}
				it++;
				buffer = *it;
				while (std::regex_match(buffer, letters_)) {
					bufSection += buffer;
					it++;
					buffer = *it;
				}
			case ']':
				if (std::regex_match(bufSection, letters_)) {
					section = bufSection;
				}
				bufSection = "";
			case '/':
				comm++;
				if (comm == 2)
					comm = 0;
				continue;
			default:
				throw TextError();
			}


		}
	}

	if (!keys.empty())
	{
		builder.AddSection(section, keys);
		keys.clear();
	}

	return builder;
}