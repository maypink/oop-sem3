#include "AllTerainBoots.h"

int AllTerainBoots::GetRestInterval() {

	return this->restInterval;

}

float AllTerainBoots::RestDuration(int time) {

	if (time > restInterval)
		return 5;
	else return 10;

}

std::string AllTerainBoots::GetName() {

	return this->name;
}

int AllTerainBoots::GetSpeed() {

	return this->speed;
}