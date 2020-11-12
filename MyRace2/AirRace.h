#pragma once
#include "IRace.h"
#include "AirVehicle.h" //���������� ������� �������� � ��� �����

class AirRace : public Race {

public:

	AirRace(int distance) : Race(distance) {}


	void RegistrateVehicle(AirVehicle* vehicle);


	std::pair<std::string, int> Run();

};