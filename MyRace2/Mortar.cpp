#include "Mortar.h"

float Mortar::DistanceReducer(int distance) {

	return 0.06;

}

std::string Mortar::GetName() {

	return this->name;
}

int Mortar::GetSpeed() {

	return this->speed;
}
