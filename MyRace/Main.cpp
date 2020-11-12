#include <iostream>
#include "AirRace.h"
#include "MagicCarpet.h"
#include "Mortar.h"
#include "Broom.h"
#include "GroundRace.h"
#include "BactrianCamel.h"
#include "SpeedBoatCamel.h"
#include "Centaur.h"
#include "AllTerainBoots.h"
#include "GeneralRace.h"

int main()
{
	try {
		AirRace race1(100000);
		race1.RegistrateVehicle(new MagicCarpet);
		race1.RegistrateVehicle(new Mortar);
		race1.RegistrateVehicle(new Broom);
		std::cout << race1.Run().first << " won in this race with time " << race1.Run().second << '\n';

		GroundRace race(1000000);
		race.RegistrateVehicle(new BactrianCamel);
		race.RegistrateVehicle(new SpeedBoatCamel);
		race.RegistrateVehicle(new Centaur);
		race.RegistrateVehicle(new AllTerainBoots);
		std::cout << race.Run().first << " won in this race with time " << race.Run().second << '\n';

		GeneralRace race2(100000); //баг время +1 по сравнению с первой гонкой в воздухе
		race2.RegistrateVehicle(new BactrianCamel);
		race2.RegistrateVehicle(new Broom);
		race2.RegistrateVehicle(new MagicCarpet);
		race2.RegistrateVehicle(new AllTerainBoots);
		std::cout << race2.Run().first << " won in this race with time " << race2.Run().second << '\n';
	}
	catch (const GetParamError & e) {

		std::cerr << "\n" << e.what() << "\n";

	}
	catch (const EmptyRaceError &e){

		std::cerr << "\n" << e.what() << "\n";

	}
	return 0;
}
