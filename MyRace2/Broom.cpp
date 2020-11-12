#include "Broom.h"

float Broom::DistanceReducer(int distance) {

	float reducer = 1;
	for (int i = 0; i < distance; i += 1000) {
		reducer -= 0.01;
	}
	return reducer;

}

std::string Broom::GetName() {

	return this->name;
}

int Broom::GetSpeed() {

	return this->speed;
}