#pragma once
#include "IVehicle.h"

class GroundVehicle : public IVehicle {

protected:

	int restInterval;

	int restDuration;

public:

	virtual int GetSpeed() = 0;

	virtual std::string GetName() = 0;

	virtual int GetRestInterval() = 0;

	virtual float RestDuration(int time) = 0;

	float Run(int distance) {
		int time = 0;
		while (distance > 0) {
			int buff = 0;
			for (int i = 0; i < GetRestInterval(); ++i) {
				buff++;
				distance -= GetSpeed();
				time++;
				if (distance <= 0)
					break;
			}
			if (buff == 30) {
				int RD = RestDuration(time);
				time = time + RD;
			}
		}
		return time;
	}

};