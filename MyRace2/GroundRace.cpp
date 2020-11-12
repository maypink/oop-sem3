#include "GroundRace.h"

void GroundRace::RegistrateVehicle(GroundVehicle* vehicle) {

	vehicles.push_back(vehicle);

}

std::pair<std::string, float> GroundRace::Run() {

	if (vehicles.size() == 0)
		throw EmptyRaceError();

	float minTime = 0;
	std::string winner = "";
	for (int i = 0; i < vehicles.size(); i++) {
		if ((*vehicles[i]).Run(this->distance) < minTime || minTime == 0) {
			minTime = (*vehicles[i]).Run(this->distance);
			winner = vehicles[i]->GetName();
		}
	}
	return std::make_pair(winner, minTime);

}
