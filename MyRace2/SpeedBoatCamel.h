#pragma once
#include "GroundVehicle.h"

class SpeedBoatCamel : public GroundVehicle {

protected:

	std::string name = "Super Fast Camel";

	int speed = 40;

	int restInterval = 10;

public:

	int GetRestInterval() override;

	float RestDuration(int time) override;

	std::string GetName() override;

	int GetSpeed() override;

};