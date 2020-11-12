#pragma once
#include "AirVehicle.h"

class Broom : public AirVehicle {

protected:

	std::string name = "Broom";

	int speed = 20;

public:

	float DistanceReducer(int distance) override {

		float reducer = 1;
		for (int i = 0; i < distance; i += 1000) {
			reducer -= 0.01;
		}
		return reducer;

	}

	std::string GetName() override {

		return this->name;
	}

	int GetSpeed() override {

		return this->speed;
	}

};