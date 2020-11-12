#pragma once
#include <vector>
#include "IVehicle.h"
#include "MyExceptions.h"

class Race {

protected:

	int distance;

	std::vector <IVehicle*> vehicles;

public:

	Race(int& distance) { 

		if (distance <= 0)
			throw GetParamError();
		this->distance = distance;
	}

};