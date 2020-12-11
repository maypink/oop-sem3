#pragma once
#include "Account.h"

class DebitAccount: public Account {

protected:
	
	std::string account_id;

	float account_balance;

	int curDate;

	float percent;

	float bufPercent;

	std::vector<std::pair<std::string, std::pair<std::string, float>>> recentOperations;
 
public:

	DebitAccount(std::string account_id, float account_balance, float percent);

	std::string GetID() override;

	float GetBalance();

	void CashWithDrawal(float summ) override;

	void ChargingOfInterests(int days);

	void Refill(float summ) override;

	virtual std::pair<int, float> RewindTime(int days);

	void Transfer(std::string type, std::string id, float summ);

	void CanselTransaction(std::string type, std::string id, float summ);

};