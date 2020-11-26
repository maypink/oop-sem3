#include "FileInfo.h"
#include <boost/filesystem.hpp>

std::string FileInfo::GetPath() {

	return filePath;

}

int FileInfo::GetSize() {
	
	namespace fs = boost::filesystem;
	const fs::path file{filePath};
	int curSize = fs::file_size(file);
	return curSize;

}

int FileInfo::GetFixSize() {

	return size;

}