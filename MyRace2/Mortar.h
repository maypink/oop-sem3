#pragma once
#include "AirVehicle.h"

class Mortar : public AirVehicle {

protected:

	std::string name = "Mortar";

	int speed = 8;

public:

	float DistanceReducer(int distance) override;

	std::string GetName() override;

	int GetSpeed() override;

};