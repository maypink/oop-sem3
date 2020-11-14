#include <iostream>
#include <iomanip>
#include <ctime>
#include "ShopsNet.h"

int main()
{
	try
	{
	ShopsNet net;
	net.NewShop(1000, "Perekrestok", "Surgut");
	net.NewShop(1001, "Magnit", "Ufa");
	net.NewShop(1002, "Azbuka Vkusa", "Perm");
	net.NewShop(1003, "Vkusvill", "Moskow");

	net.NewProduct(1, "Milk");
	net.NewProduct(2, "Tea");
	net.NewProduct(3, "Coffee");
	net.NewProduct(4, "RedBull");
	net.NewProduct(5, "Ice Cream");
	net.NewProduct(6, "Kinder King");
	net.NewProduct(7, "Cheese");
	net.NewProduct(8, "Banana");
	net.NewProduct(9, "Bubble Gum");
	net.NewProduct(10, "Water");


	for (int i = 1000; i < 1004; ++i) {
		std::map <int, std::pair<int, float>> products;
		for (int j = 1; j < 11; ++j) {
			int amount = rand() % 2 + 10;
			float price = (rand() % 1000 + 50) / 11;
			products.insert(std::make_pair(j, std::make_pair(amount, price)));
		}
		net.AddBanchInShop(i, products);
	}

	
	//Task 4
	std::cout << "Let's find the cheapest milk\n";
	std::pair <int, float> result4 = net.FindTheCheapest(1);
	std::cout << "You can buy the cheapest milk in " << net.GetSName(result4.first) << " shop and it will cost you " << result4.second << " rubles\n";
	

	//Task 5
	std::cout << "\n\nHow much money do you have?\n";
	int money;
	std::cin >> money;
	std::cout << "In what shop you wanna spend your money?\n";

	
		int keyS;
		std::cin >> keyS;
		//net.CheckShopExistence(keyS);

		std::cout << "So now you have only " << money << " rubles:(. \nLet's find out what you buy in " << keyS << " shop.\n";
		std::map <int, int> result = net.FixSumm(keyS, money);
		std::cout << "PRODUCT" << "   " << "AMOUNT\n";
		for (auto it = result.begin(); it != result.end(); it++) {
			std::cout << net.GetPName(it->first);
			std::cout << std::setw(10) << it->second << "\n";
		}


		//Task 6
		std::cout << "\n\nIt's time to buy something! Enter shop id\n";
		int keyS2;
		std::cin >> keyS2;
		//net.CheckShopExistence(keyS2);
		std::vector <std::pair<int, int>> products2 = { {1, 10}, {2, 5}, {3, 3}, {7, 2} };
		std::cout << "Total summ is " << net.BuyBanch(keyS2, products2) << '\n';


		//Task 7
		std::cout << "\n\nLet's find the cheapest batch of products!\n";
		std::vector <std::pair<int, int>> products3 = { {1, 10}, {2, 1}, {5, 3}, {7, 2} };
		std::cout << "The shop is " << net.GetSName(net.FindTheCheapestBanch(products3).first) << " "
			<< "\nThe total summ is " << net.FindTheCheapestBanch(products3).second << '\n'; 
	}

	catch (const GetParamError &e) {

		std::cerr << "\n" << e.what() << "\n";

	}
	catch (const AvailabilityError & e) {

		std::cerr << "\n" << e.what() << "\n";

	}
	catch (const UniqueIDError & e) {

		std::cerr << "\n" << e.what() << "\n";

	}
}