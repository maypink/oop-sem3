#include "SpeedBoatCamel.h"

int SpeedBoatCamel::GetRestInterval() {

	return this->restInterval;

}

float SpeedBoatCamel::RestDuration(int time) {

	if (time > 2 * restInterval)

		return 8;

	else if (time > restInterval)

		return 6.5;

	else return 5;

}

std::string SpeedBoatCamel::GetName() {

	return this->name;
}

int SpeedBoatCamel::GetSpeed() {

	return this->speed;
}