#pragma once
#include "IRace.h"
#include "GroundVehicle.h"

class GroundRace : public Race {

public:

	GroundRace(int distance) : Race(distance) {}


	void RegistrateVehicle(GroundVehicle* vehicle);

	std::pair<std::string, float> Run();


};