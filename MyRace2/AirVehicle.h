#pragma once
#include "IVehicle.h"

class AirVehicle : public IVehicle {

public:

	virtual float DistanceReducer(int distance) = 0;

	virtual int GetSpeed() = 0;

	virtual std::string GetName() = 0;

	float Run(int distance) {

		return (distance * (1 - DistanceReducer(distance)) / GetSpeed());
	}

};

