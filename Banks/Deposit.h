#pragma once
#include "Account.h"

class Deposit : public Account {

protected:

	std::string account_id;

	float account_balance;

	int curDate;

	float percent;

	int account_term; //срок счета

	float bufPercent;

	std::vector<std::pair<std::string, std::pair<std::string, float>>> recentOperations;

public:

	Deposit(std::string account_id, float account_balance, float percent, int account_term);

	std::string GetID() override;

	float GetBalance();

	void SetAccountTerm(int accountTerm);

	void CashWithDrawal(float summ) override;

	void Refill(float summ) override;

	void ChargingOfInterests(int days);

	virtual std::pair<int, float> RewindTime(int days);

	void Transfer(std::string type, std::string id, float summ);

	void CanselTransaction(std::string type, std::string id, float summ);

};