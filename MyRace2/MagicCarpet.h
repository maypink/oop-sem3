#pragma once
#include "AirVehicle.h"

class MagicCarpet : public AirVehicle {

protected:

	std::string name = "Magic Carpet";

	int speed = 10;

public:

	float DistanceReducer(int distance) override;

	std::string GetName() override;

	int GetSpeed() override;

};