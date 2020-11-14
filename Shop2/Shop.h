#pragma once
#include <string>
#include <map>
#include <vector>
#include "Product.h"

class Shop {
	 
private:

	int key;

	std::string name;

	std::string address;
	
	std::map <int, std::pair<int, float>> assort;


public:

	Shop(int &key, std::string name, std::string address);

	~Shop() = default;

	int GetKey();

	std::string GetName();

	void AddBatch(std::map <int, std::pair<int, float>> products);

	void AddProduct(int key, int& amount, float& price); //добавить в конкретный магаз

	float BuyProduct(std::pair<int, int>& product);

	void ChangeAmount(int& key, int &amount);

	void ChangePrice(int& key, float &price);

	float CheckPrice(int& keyP);

	int CheckAmount(int &keyP);

	std::map <int, int> FixSumm(int &money);

	void ShowAssort();
};