#include <iostream>
#include "BanksManager.h"


int main()
{
	try {
		BankManager bankManager;

		bankManager.CreateNewBank(5, 6, 7, 360, 10000, 5000);//0
		bankManager.CreateNewBank(3, 2, 5, 180, 100000, 4000);//1
		bankManager.CreateNewBank(4, 4.5, 5.3, 720, 20000, 3000);//2
		Client Shrek;
		bankManager.CreateAccountForClient(Shrek, "1", "credit", 1000);
		bankManager.CreateAccountForClient(Shrek, "2", "deposit", 40000);
		bankManager.ShowAll();
		std::cout << "Enter recipient and sender id:\n";
		std::string id1, id2;
		std::cin >> id1 >> id2;
		std::cout << "Now enter summ that you wanna transfer:\n";
		float summ;
		std::cin >> summ;
		bankManager.TransferMoney(id1, id2, summ);
		bankManager.ShowAll();
		std::cout << "Now let's rewind time. Enter the account id and the amount of days:\n";
		std::string id;
		int days;
		std::cin >> id >> days;
		bankManager.RewindTime(id, days);
		std::cout << "Enter what type of transaction you would like to cancel {'transfer', 'refill', 'drawal'}:\n";
		std::string type;
		std::cin >> type;
		std::cout << "Enter id recipient and id transfer or just one id if type is 'refill' or 'drawal':\n";
		std::string ID, ID2;
		std::cin >> ID >> ID2;
		std::cout << "Enter the summ of the operation:\n";
		float summ2;
		std::cin >> summ2;
		bankManager.CancellTransaction(type, ID, ID2, summ2);
		bankManager.ShowAll();
	}
	catch (const ExcessError & e) {

		std::cerr << "\n" << e.what() << "\n";

	}
	catch (const ExistenceError & e) {

		std::cerr << "\n" << e.what() << "\n";

	}

}

