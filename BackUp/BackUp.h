#pragma once
#include <boost/filesystem.hpp>
#include <iostream>
#include "RestorePoint.h"
#include "ClearingAlgorithm.h"


class BackUp {

private:

	int ID; //подумай над айдишником

	int amountOfFullRP = 0;

	int size; 

	std::vector <RestorePoint> points;

	std::vector <FileInfo> curFiles;


public:

	BackUp() = default;

	void CreateBackUp(std::string path);

	std::vector <FileInfo> GetFiles();

	void ShowFiles();

	int GetSize();

	int GetFilesSize();

	void CreateFullRestorePoint();

	void CreateIncRestorePoint();

	std::vector <RestorePoint> GetRestorePoints();

	void ShowRestorePoints();

	void DeleteFile(std::string path);

	void AddFile(std::string path);

	void SeparateStorage();

	void GeneralStorage();

	void ClearByAmountBU(int amount);

	void ClearByTime(time_t time);

	void ClearBySize(int size);

	void ClearByAll(int amount, time_t time, int size);

	void ClearByOne(int amount, time_t time, int size);

	friend class ClearingAlgorithm;

};

