#pragma once
#include "BackUp.h"

class ClearingAlgorithm {

private:



public:

	void ClearByAmount(std::vector <RestorePoint> &points, int amount);

	void ClearByDate(std::vector <RestorePoint>& points, time_t time);

	void ClearBySize(std::vector <RestorePoint>& points, int size);

	friend class BackUp;

};
