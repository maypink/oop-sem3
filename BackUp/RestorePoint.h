#pragma once
#include <vector>
#include "FileInfo.h"


class RestorePoint {

private:

	time_t time;

	int size;

	std::vector <FileInfo> files;

	bool type;


public:

	//RestorePoint(char time, BackUp backup);

	RestorePoint(int size, std::vector <FileInfo> &files);

	void SetTime(time_t time);

	int GetSize();

	std::vector <FileInfo> GetFiles();

	void ShowFiles();

	time_t GetTime();

	void SetType(bool type);

	friend class ClearingAlgorithm;

};