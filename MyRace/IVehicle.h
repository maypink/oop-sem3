#pragma once
#include <iostream>

class IVehicle {

public:

	virtual std::string GetName() = 0;

	virtual int GetSpeed() = 0;

	virtual float Run(int distance) = 0;

};