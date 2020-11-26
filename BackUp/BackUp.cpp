#define _CRT_SECURE_NO_WARNINGS
#include "BackUp.h"

void BackUp::CreateBackUp(std::string path) {
	
	boost::filesystem::directory_iterator begin(path);
	boost::filesystem::directory_iterator end;
	for (; begin != end; ++begin) {
		std::string cur = "";
		boost::filesystem::path p(begin->path());
		boost::filesystem::file_status fs = boost::filesystem::status(*begin); {
			switch (fs.type()) {
			case boost::filesystem::regular_file:
				//std::cout << "FILE ";
				cur = "file";
				break;
			case boost::filesystem::symlink_file:
				break;
			case boost::filesystem::directory_file:
				cur = "dir";
				break;
			}

			if (cur == "dir") {
				//std::cout << boost::filesystem::basename(*begin) << "\n"; //будет "test2"
				std::string curDirectory = path + '/' + boost::filesystem::basename(*begin);
				//std::cout << curDirectory << "\n\n";
				CreateBackUp(curDirectory);

			}
			if (cur == "file") {

				std::string curPath = p.parent_path().string() + "/" + p.filename().string();
				//this->size += boost::filesystem::file_size(*begin);
				FileInfo file(curPath, boost::filesystem::file_size(*begin));
				curFiles.push_back(file);

			}
		}
	}
}


std::vector <FileInfo> BackUp::GetFiles() {

	return curFiles;

}

void BackUp::ShowFiles() {

	std::cout << "PATH" << "            " << "SIZE\n";
	for (int i = 0; i < curFiles.size(); ++i) {
		std::cout << curFiles[i].GetPath() << " " << curFiles[i].GetFixSize() << "\n";
	}

}

int BackUp::GetSize() {

	return size;

}

int BackUp::GetFilesSize() {

	int size = 0;
	for (int i = 0; i < curFiles.size(); ++i) {
		size += curFiles[i].GetSize();
	}
	return size;

}


void BackUp::CreateFullRestorePoint() {

	int size = GetFilesSize();

	std::vector<FileInfo> curfiles;

	for (int i = 0; i < curFiles.size(); ++i) {
		std::string curPath = curFiles[i].GetPath();
		int curSize = curFiles[i].GetSize();
		FileInfo curFile(curPath, curSize);
		curfiles.push_back(curFile);
	}

	time_t now = time(0);
	RestorePoint rPoint(size, curfiles); 
	this->size = this->size + size;
	rPoint.SetTime(now);
	rPoint.SetType(1); //full
	points.push_back(rPoint);
	amountOfFullRP++;


}

void BackUp::CreateIncRestorePoint() {

	if (!amountOfFullRP)
		throw IncrementPointError();

	int size = GetFilesSize();

	std::vector<FileInfo> curfiles;

	for (int i = 0; i < curFiles.size(); ++i) {
		std::string curPath = curFiles[i].GetPath();
		int curSize = curFiles[i].GetSize();
		FileInfo curFile(curPath, curSize);
		curfiles.push_back(curFile);
	}

	time_t now = time(0);
	RestorePoint rPoint(size, curfiles); 
	this->size = this->size + size;
	rPoint.SetTime(now);
	points.push_back(rPoint);
	rPoint.SetType(0); //inc

}


std::vector <RestorePoint> BackUp::GetRestorePoints() {

	return points;

}

void BackUp::ShowRestorePoints() {
	std::cout << "\n\n";

	for (int i = 0; i < points.size(); ++i) {
		time_t time = points[i].GetTime();
		tm* timeinfo = localtime(&time);
		std::cout << "The time point was created: "<< asctime(timeinfo) << 
			"Time in sec format: "<<points[i].GetTime()<<"\n"
			"The point size: "<< points[i].GetSize() << "\n";
		std::cout << "The following files are in point:\n ";
		points[i].ShowFiles();
		std::cout << "\n";
	}
	std::cout << "\n\n";
}


void BackUp::DeleteFile(std::string path) {

	int num = -1;
	for (int i = 0; i < curFiles.size(); ++i) {
		if (curFiles[i].GetPath() == path)
			num = i;
	}
	if (num == -1)
		throw ExistenceError();

	curFiles.erase(curFiles.begin() + num);
	/*if (curFiles.size() != 0) {
		for (int i = num-1; i < curFiles.size() - 1; ++i) {
			curFiles[i] = curFiles[i + 1];
		}
		curFiles.pop_back();
	}*/

}

void BackUp::AddFile(std::string path) {

	namespace fs = boost::filesystem;
	const fs::path file{ path };
	std::fstream f(path, std::ios::in);

	if (!f.is_open())
		throw ExistenceError();

	int size = fs::file_size(file);

	FileInfo fileInfo(path, size);
	curFiles.push_back(fileInfo);

}

void BackUp::SeparateStorage() {

	std::cout << "You've successfully saved the object to the folder\n";

}

void BackUp::GeneralStorage() {

	std::cout << "You've successfully saved the object to the archive\n";

}

void BackUp::ClearByAmountBU(int amount) {

	if (amount < 0)
		throw GetParamError();

	ClearingAlgorithm a;
	a.ClearByAmount(this->points, amount);

}

void BackUp::ClearByTime(time_t time) {

	ClearingAlgorithm a;
	a.ClearByDate(this->points, time);

}

void BackUp::ClearBySize(int size) {

	ClearingAlgorithm a;
	a.ClearBySize(this->points, size);

}

void BackUp::ClearByAll(int amount, time_t time, int size) {

	std::vector <RestorePoint> pointsAmount = this->points;
	std::vector <RestorePoint> pointsTime = this->points;
	std::vector <RestorePoint> pointsSize = this->points;

	ClearingAlgorithm a;

	a.ClearByAmount(pointsAmount, amount);
	a.ClearByDate(pointsTime, time);
	a.ClearBySize(pointsSize, size);

	size_t resSize = std::max(pointsAmount.size(), pointsTime.size());
	resSize = std::max(resSize, pointsSize.size());
	if (resSize!=points.size())
		this->points.erase(points.begin(), points.end() - resSize - 1);

}

void BackUp::ClearByOne(int amount, time_t time, int size) {

	ClearByAmountBU(amount);
	ClearByTime(time);
	ClearBySize(size);

}