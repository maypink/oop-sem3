#pragma once
#include <vector>
#include "Shop.h"

class ShopsNet {

private:

	/*std::map <int, std::pair<int, float>> products;

	std::map <int, std::map <int, std::pair<int, float>>> Net;*/

	std::vector <Shop> allShops;

	std::vector <Product> allProducts;

public:

	int GetSKey(int &key);

	int GetPKey(int& key);

	std::string GetSName(int key);

	std::string GetPName(int key);

	void NewShop();

	void NewShop(int key, std::string name, std::string address);

	void NewProduct(); //добавить новый продукт в общий список, но не в конкретный магаз

	void NewProduct(int key, std::string name);

	void AddBanchInShop(int& keyS, std::map <int, std::pair<int, float>> products); //пара: код продукта и его кол-во 

	std::pair <int, float> FindTheCheapest(int keyP);

	std::pair<int, float> FindTheCheapestBanch(std::vector <std::pair<int, int>>& products);

	std::map <int, int> FixSumm(int &keyS, int &money);

	std::string BuyBanch(int& keyS, std::vector <std::pair<int, int>>& products);

	void CheckShopExistence(int &key);

	void CheckProdExistence(int &key);

	void ShowAssort(int &keyS);

};