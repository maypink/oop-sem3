#pragma once
#include "GroundVehicle.h"

class BactrianCamel : public GroundVehicle {

protected:

	std::string name = "Bactrian Camel";

	int speed = 10;

	int restInterval = 30;

public:

	int GetRestInterval() override;

	float RestDuration(int time) override;

	std::string GetName() override;

	int GetSpeed() override;

};