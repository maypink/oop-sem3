#include "MagicCarpet.h"

float MagicCarpet::DistanceReducer(int distance) {

	if (distance < 1000) return 0.0;
	if (distance >= 1000 && distance < 5000) return 0.03;
	if (distance >= 5000 && distance < 10000) return 0.1;
	if (distance >= 10000) return 0.05;

}

std::string MagicCarpet::GetName() {

	return this->name;
}

int MagicCarpet::GetSpeed() {

	return this->speed;
}
