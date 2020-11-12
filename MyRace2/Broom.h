#pragma once
#include "AirVehicle.h"

class Broom : public AirVehicle {

protected:

	std::string name = "Broom";

	int speed = 20;

public:

	float DistanceReducer(int distance) override;

	std::string GetName() override;

	int GetSpeed() override;
};