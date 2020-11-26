#include "ClearingAlgorithm.h"

void ClearingAlgorithm::ClearByAmount(std::vector <RestorePoint> &points, int amount) {

	int interval = 0;

	if (points[points.size() - amount].type == 1) {
		points.erase(points.begin(), points.end() - amount);
	}
	else {

		//сорри братишка точек больше
		std::cout << "There are more points than you tried to save because of incremental points\n";
		int i = points.size() - amount - 1;
		while (points[i].type==0) {
			i--;
		}
		if (i!=0)
			points.erase(points.begin(), points.begin() + i);
	}

}

void ClearingAlgorithm::ClearByDate(std::vector <RestorePoint>& points, time_t time) {

	int border = -1;

	for (int i = points.size()-1; i >= 0; --i) {
		if (points[i].time < time) {
			border = i;
			break;
		}
		else {
			continue;
		}
	}

	if (border != -1) {
		points.erase(points.begin(), points.begin() + border);
	}

	/*for (int i = 0; i < points.size(); ++i) { 
		if (points[i].time <= time) {
			continue;
		}
		else {
			border = i;
			break;
		}
	}
	if (border!=0)
		points.erase( points.begin() + border, points.end());*/

}

void ClearingAlgorithm::ClearBySize(std::vector <RestorePoint>& points, int size) {

	int curSize = 0;
	int border = -1;
	bool flag = false;
	for (int i = points.size() - 1; i >= 0; --i) {

		curSize += points[i].size;
		if ((curSize > size) && (points[i].type == 1))  {
			border = i;
			break;
		}
		else if (curSize > size) {
			flag = true;
		}


	}

	if (flag)

		std::cout << "There are more points than you tried to save because of incremental points\n";

	if (curSize > size) {

		if (border != -1)
			points.erase(points.begin() + border, points.end());
		else
			points.erase(points.begin());

	}

}
