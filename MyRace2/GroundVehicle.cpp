#include "GroundVehicle.h"

float GroundVehicle::Run(int distance) {
	int time = 0;
	while (distance > 0) {
		int buff = 0;
		for (int i = 0; i < GetRestInterval(); ++i) {
			buff++;
			distance -= GetSpeed();
			time++;
			if (distance <= 0)
				break;
		}
		if (buff == 30) {
			int RD = RestDuration(time);
			time = time + RD;
		}
	}
	return time;
}