#pragma once
#include "GroundVehicle.h"

class BactrianCamel : public GroundVehicle {

protected:

	std::string name = "Bactrian Camel";

	int speed = 10;

	int restInterval = 30;

public:

	int GetRestInterval() override {

		return this->restInterval;

	}

	float RestDuration(int time) override {

		if (time > restInterval)
			return 8;
		else return 5;

	}

	std::string GetName() override {

		return this->name;
	}

	int GetSpeed() override {

		return this->speed;
	}

};