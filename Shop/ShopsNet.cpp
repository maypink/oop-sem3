#pragma once
#include "ShopsNet.h"

int ShopsNet::GetSKey(int &key) {

	for (int i = 0; i < allShops.size(); ++i) {
		if (allShops[i].GetKey() == key) {
			return allShops[i].GetKey();
		}
	}

}

int ShopsNet::GetPKey(int& key) {

	for (int i = 0; i < allProducts.size(); ++i) {
		if (allProducts[i].GetKey() == key) {
			return allProducts[i].GetKey();
		}
	}

}


std::string ShopsNet::GetSName(int key) {

	for (int i = 0; i < allShops.size(); ++i) {
		if (allShops[i].GetKey() == key) {
			return allShops[i].GetName();
		}
	}

}

std::string ShopsNet::GetPName(int key) {

	for (int i = 0; i < allProducts.size(); ++i) {
		if (allProducts[i].GetKey() == key) {
			return allProducts[i].GetName();
		}
	}

}

void ShopsNet::NewProduct() {

	int key;
	std::string name;

	std::cout << "What id does the product have?\n";
	std::cin >> key;

	std::cout << "What is the name of the product?\n";
	std::cin >> name;

	Product product(key, name);

	allProducts.push_back(product);

}

void ShopsNet::NewProduct(int key, std::string name) {

	Product product(key, name);

	allProducts.push_back(product);

}

void ShopsNet::NewShop() {

	int key;
	std::string name;
	std::string address;

	std::cout << "What id does the shop have?\n";
	std::cin >> key;

	std::cout << "What is the name of the shop?\n";
	std::cin >> name;

	std::cout << "What is the adress of the shop?\n";
	std::cin >> address;

	Shop shop(key, name, address);

	allShops.push_back(shop);

}

void ShopsNet::NewShop(int key, std::string name, std::string address) { //key мб через ссылку подумай над этимм

	Shop shop(key, name, address);

	allShops.push_back(shop);

}

void ShopsNet::AddBanchInShop(int& keyS, std::map <int, std::pair<int, float>> products) {

	for (auto it = products.begin(); it != products.end(); it++) {

		for (int i = 0; i < allShops.size(); ++i) {
			if (allShops[i].GetKey() == keyS) {
				allShops[i].AddProduct(it->first, it->second.first, it->second.second );
				break;
			}
		}
	}

}

std::pair <int, float> ShopsNet::FindTheCheapest(int keyP) {

	int shop = allShops[0].GetKey();
	float minPrice = allShops[0].CheckPrice(keyP);

	for (int i = 0; i < allShops.size(); ++i) {
		if (allShops[i].CheckPrice(keyP) < minPrice) {
			shop = allShops[i].GetKey();
			minPrice = allShops[i].CheckPrice(keyP);
		}
	}

	return std::make_pair(shop, minPrice);

}

std::pair<int, float> ShopsNet::FindTheCheapestBanch(std::vector <std::pair<int, int>>& products) { //код и кол-во

	float curTotal = 0;
	float minTotal = 0;
	int shop = 0;

	for (int i = 0; i < allShops.size(); ++i) {
		for (int j = 0; j < products.size(); ++j) {
			if (allShops[i].CheckAmount(products[j].first) >= products[j].second)
				curTotal += allShops[i].CheckPrice(products[j].first) * products[j].second;
			else break;
		}
		if ((curTotal < minTotal || minTotal==0) && (curTotal!=0)) {
			minTotal = curTotal;
			shop = allShops[i].GetKey();
		}
		curTotal = 0;
	}

	if (!minTotal)
		throw AvailabilityError();

	return std::make_pair(shop, minTotal);

}

std::map <int, int> ShopsNet::FixSumm(int &keyS, int& money) {

	for (int i = 0; i < allShops.size(); ++i) {
		if (allShops[i].GetKey() == keyS) {
			return allShops[i].FixSumm(money);
		}
	}
}

std::string ShopsNet::BuyBanch(int& keyS, std::vector <std::pair<int, int>>& products) {

	float total = 0;
	for (int i = 0; i < allShops.size(); ++i) {
		if (allShops[i].GetKey() == keyS) {
			for (int j = 0; j < products.size(); ++j) {
				/*if (allShops[i].BuyProduct(products[j]) < 0) //столько продуктов нет
					return "there is no enough products for you:(\n";*/
				total += allShops[i].BuyProduct(products[j]);
			}
			return std::to_string(total);
		}
	}

}

void ShopsNet::CheckShopExistence(int &key) {

	bool flag = false;
	for (int i = 0; i < allShops.size(); ++i) {
		if (allShops[i].GetKey() == key)
			flag = true;
	}
	if (!flag)
		throw GetParamError();

}

void ShopsNet::CheckProdExistence(int& key) {

	bool flag = false;
	for (int i = 0; i < allProducts.size(); ++i) {
		if (allProducts[i].GetKey() == key)
			flag = true;
	}
	if (!flag)
		throw GetParamError();
}

void ShopsNet::ShowAssort(int &keyS) {

	for (int i = 0; i < allShops.size(); ++i) {
		if (allShops[i].GetKey() == keyS) {
			allShops[i].ShowAssort();
			break;
		}
	}
}