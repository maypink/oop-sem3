#pragma once
#include "GroundVehicle.h"

class AllTerainBoots : public GroundVehicle {

protected:

	std::string name = "All Terain Boots";

	int speed = 6;

	int restInterval = 60;

public:

	int GetRestInterval() override;

	float RestDuration(int time) override;

	std::string GetName() override;

	int GetSpeed() override;

}; 
