#pragma once
#include <iostream>
#include <string>
#include "MyExceptions.h"

class Product {

private:

	int key;

	std::string name;

	friend class Shop;

	friend class ShopNet;

public:

	Product(int& key, std::string& name);

	~Product() = default;

	int GetKey();

	std::string GetName();

};
