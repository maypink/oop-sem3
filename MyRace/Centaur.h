#pragma once
#include "GroundVehicle.h"

class Centaur : public GroundVehicle {

protected:

	std::string name = "Centaur";

	int speed = 15;

	int restInterval = 8;

public:

	int GetRestInterval() override {

		return this->restInterval;

	}

	float RestDuration(int time) override {

		return 8;

	}

	std::string GetName() override {

		return this->name;
	}

	int GetSpeed() override {

		return this->speed;
	}

};