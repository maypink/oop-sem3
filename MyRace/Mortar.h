#pragma once
#include "AirVehicle.h"

class Mortar : public AirVehicle {

protected:

	std::string name = "Mortar";

	int speed = 8;

public:

	float DistanceReducer(int distance) override {

		return 0.06;

	}

	std::string GetName() override {

		return this->name;
	}

	int GetSpeed() override {

		return this->speed;
	}

};