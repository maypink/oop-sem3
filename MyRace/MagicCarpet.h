#pragma once
#include "AirVehicle.h"

class MagicCarpet : public AirVehicle {

protected:

	std::string name = "Magic Carpet";

	int speed = 10;

public:

	float DistanceReducer(int distance) override {

		if (distance < 1000) return 0.0;
		if (distance >= 1000 && distance < 5000) return 0.03;  
		if (distance >= 5000 && distance < 10000) return 0.1;
		if (distance >= 10000) return 0.05;

	}

	std::string GetName() override {

		return this->name;
	}

	int GetSpeed() override {

		return this->speed;
	}

};