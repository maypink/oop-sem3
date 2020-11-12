#include "BactrianCamel.h"

int BactrianCamel::GetRestInterval() {

	return this->restInterval;

}

float BactrianCamel::RestDuration(int time) {

	if (time > restInterval)
		return 8;
	else return 5;

}

std::string BactrianCamel::GetName() {

	return this->name;
}

int BactrianCamel::GetSpeed() {

	return this->speed;
}