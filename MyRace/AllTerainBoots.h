#pragma once
#include "GroundVehicle.h"

class AllTerainBoots : public GroundVehicle {

protected:

	std::string name = "All Terain Boots";

	int speed = 6;

	int restInterval = 60;

public:

	int GetRestInterval() override {

		return this->restInterval;

	}

	float RestDuration(int time) override {

		if (time > restInterval)
			return 5;
		else return 10;

	}

	std::string GetName() override {

		return this->name;
	}

	int GetSpeed() override {

		return this->speed;
	}

}; 
