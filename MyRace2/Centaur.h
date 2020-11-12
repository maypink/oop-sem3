#pragma once
#include "GroundVehicle.h"

class Centaur : public GroundVehicle {

protected:

	std::string name = "Centaur";

	int speed = 15;

	int restInterval = 8;

public:

	int GetRestInterval() override;

	float RestDuration(int time) override;

	std::string GetName() override;

	int GetSpeed() override;

};