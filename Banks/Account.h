#pragma once
#include <string>
#include <cmath>
#include <iostream>
#include <vector>
#include "MyException.h"

class Account {

protected:

	std::string account_id;

	float account_balance;

	float percent;

public:

	virtual void CashWithDrawal(float summ);

	virtual void Refill(float summ);

	virtual std::pair<int, float> RewindTime(int days) = 0;

	virtual std::string GetID();

	virtual void Transfer(std::string type, std::string id, float summ) = 0;

	virtual void CanselTransaction(std::string type, std::string id, float summ) = 0;

	virtual float GetBalance();


};