#include "Product.h"

Product::Product(int& key, std::string& name) {

	this->key = key;
	this->name = name;

}

std::string Product::GetName() {

	return this->name;
}


int Product::GetKey() {

	return this->key;

}


