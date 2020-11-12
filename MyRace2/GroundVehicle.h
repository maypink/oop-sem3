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

	float Run(int distance);

};