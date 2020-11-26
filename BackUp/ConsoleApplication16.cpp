#define _CRT_SECURE_NO_WARNINGS
#include <boost/filesystem.hpp>
#include <iostream>
#include "ClearingAlgorithm.h"

int main() 
{

	// Test #1
	std::cout << "TASK 1\n\n\n";
	std::cout << "Enter the path to folder:\n";
	std::string path;
	std::cin >> path;

	BackUp a;
	a.CreateBackUp(path); 
	a.CreateFullRestorePoint();
	a.ShowRestorePoints(); 
	a.CreateFullRestorePoint();
	a.ShowRestorePoints();
	int amount;
	std::cout << "Enter the max amount of recover points:\n";
	std::cin >> amount;
	a.ClearByAmountBU(amount);
	a.ShowRestorePoints();

	std::cout << "TASK 2\n\n\n";
	// Task #2
	std::cout << "Enter the path to folder:\n";
	std::string path2;
	std::cin >> path2;

	BackUp b;
	b.CreateBackUp(path2);
	b.CreateFullRestorePoint();
	b.CreateFullRestorePoint();
	b.ShowRestorePoints();
	std::cout << "\nThe backup size: " << b.GetSize() << "\n\n\n";
	int size = 300000000;
	b.ClearBySize(size);
	b.ShowRestorePoints();

	//Task #3
	std::cout << "\nTASK 3\n\n\n";
	BackUp c;
	c.CreateBackUp(path);
	c.CreateFullRestorePoint();
	c.CreateFullRestorePoint();
	c.CreateFullRestorePoint();
	c.CreateFullRestorePoint();
	c.CreateFullRestorePoint();
	c.CreateFullRestorePoint();
	c.ShowRestorePoints();
	std::cout << "\n\n\n";
	int amount2, size2;
	time_t time2;
	std::cout << "\nHybrid cleaning algorithm if the point does not meet all parameters:\n";
	std::cout << "Enter amount, time and size:\n";
	std::cin >> amount2 >> time2 >> size2;
	c.ClearByAll(amount2, time2, size2);
	std::cout << "\n\nRESULT: \n";
	c.ShowRestorePoints();
	std::cout << "\n\n\n";

    std::cout << "NEW BACKUP: \n\n\n";
	BackUp d;
	d.CreateBackUp(path);
	d.CreateFullRestorePoint();
	d.CreateFullRestorePoint();
	d.CreateFullRestorePoint();
	d.CreateFullRestorePoint();
	d.CreateFullRestorePoint();
	d.CreateFullRestorePoint();
	d.ShowRestorePoints();
	std::cout << "\n\n\n";
	std::cout << "\nHybrid cleaning algorithm if the point does not match at least one parameter:\n";
	d.ClearByOne(amount2, time2, size2);
	std::cout << "\n\nRESULT: \n";
	d.ShowRestorePoints();
	std::cout << "\n\n\n";

}

