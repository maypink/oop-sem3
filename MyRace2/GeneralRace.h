#pragma once
#include "IRace.h"
#include "AirVehicle.h"
#include "GroundVehicle.h"

class GeneralRace : public Race {

public:

	GeneralRace(int distance) : Race(distance) {}

	void RegistrateVehicle(IVehicle* vehicle);

	std::pair<std::string, float> Run();

};