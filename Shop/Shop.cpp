#pragma once
#include "Shop.h"

Shop::Shop(int& key, std::string name, std::string address) {

	this->key = key;
	this->name = name;
	this->address = address;

}

int Shop::GetKey() {

	return this->key;

}

std::string Shop::GetName() {

	return this->name;

}

void Shop::AddBatch(std::map <int, std::pair<int, float>> products) {

	for (auto it = products.begin(); it != products.end(); it++) {
		AddProduct(it->first, it->second.first, it->second.second);
	}

}

void Shop::ChangeAmount(int& key, int &amount) {
	
	auto it = assort.find(key);
	(*it).second.first = amount;

}

void Shop::ChangePrice(int& key, float &price) {

	auto it = assort.find(key);
	(*it).second.second = price;

}

void Shop::AddProduct(int key, int &amount, float &price) {

	if (this->assort.find(key) == this->assort.end()) {

		this->assort.insert(std::make_pair(key, std::make_pair(amount, price)));

	} else {

		auto it = this->assort.find(key);
		(*it).second.first += amount;

	}
}

float Shop::CheckPrice(int& keyP) {

	return (*assort.find(keyP)).second.second;

}

int Shop::CheckAmount(int &keyP) {

	if ((assort.find(keyP)==assort.end()))
		return 0;
	else return (*assort.find(keyP)).second.first;

}

std::map <int, int> Shop::FixSumm(int& money) {

	int totalAmount = 0;

	std::map <int, int> result;
	
	if (assort.begin() == assort.end())
		throw AvailabilityError();

	for (auto it = assort.begin(); it != assort.end(); it++) {
		totalAmount += it->second.first;
		int amount = money / it->second.second;
		if (it->second.first < amount)
			amount = it->second.first;
		result.insert(std::make_pair(it->first, amount));
	}

	if (!totalAmount)
		throw AvailabilityError();
	else return result;
}

float Shop::BuyProduct(std::pair<int, int>& product) { //код продукта и его кол-во
	float summ = 0;
	for (auto it = assort.begin(); it != assort.end(); it++) {
		if (it->first == product.first) {
			if (it->second.first >= product.second) {
				it->second.first -= product.second;
				summ += it->second.second * product.second;
			}
			else throw AvailabilityError();
		}
	}
	return summ;
}

void Shop::ShowAssort() {

	for (auto it = assort.begin(); it != assort.end(); it++) {
		std::cout << "UUID" << " " << "AMOUNT" << " " << "PRICE";
		std::cout << it->first << "  " << it->second.first << " " << it->second.second << "\n";
	}

}
