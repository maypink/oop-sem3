#pragma once
#include <ctime>
#include <string>
#include "MyException.h"

class FileInfo {

private:

	std::string filePath;

	int size;

public :

	FileInfo(std::string filePath, int size) {

		this->filePath = filePath;
		this->size = size;

	}

	std::string GetPath();

	int GetSize();

	int GetFixSize();

	//все геты 

};