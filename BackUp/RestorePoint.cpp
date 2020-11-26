#define _CRT_SECURE_NO_WARNINGS
#include "RestorePoint.h"
#include <iostream>

RestorePoint::RestorePoint( int size, std::vector <FileInfo>& files) {

	this->size = size;
	this->files = files;

}

void RestorePoint::SetTime(time_t time) {
	this->time = time;
}

int RestorePoint::GetSize() {

	return size;

	/*int curSize = 0;
	for (int i = 0; i < files.size(); ++i) {
		curSize += files[i].GetSize();
	}
	return curSize;*/
}

std::vector <FileInfo> RestorePoint::GetFiles() {

	return files;

}

void RestorePoint::ShowFiles() {

	std::cout << "PATH" << "         " << "SIZE\n";
	for (int i = 0; i < files.size(); ++i) {
		std::cout << files[i].GetPath()<< " " << files[i].GetFixSize() << "\n";
	}

}

time_t RestorePoint::GetTime() {

	return this->time;

}

void RestorePoint::SetType(bool type) {

	this->type = type;

}
