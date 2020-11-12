#pragma once
#include "GroundVehicle.h"

class SpeedBoatCamel : public GroundVehicle {

protected:

	std::string name = "Super Fast Camel";

	int speed = 40;

	int restInterval = 10;

public:

	int GetRestInterval() override {

		return this->restInterval;

	}

	float RestDuration(int time) override {

		if (time > 2 * restInterval)

			return 8;

		else if (time > restInterval)

			return 6.5;

		else return 5;

	}

	std::string GetName() override {

		return this->name;
	}

	int GetSpeed() override {

		return this->speed;
	}

};