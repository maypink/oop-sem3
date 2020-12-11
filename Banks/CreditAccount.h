#pragma once
#include "Account.h"

class CreditAccount : public Account {

protected:

	std::string account_id;

	float account_balance;

	int curDate;

	float credit_limit;

	float commission;

	std::vector<std::pair<std::string, std::pair<std::string, float>>> recentOperations;

public:

	CreditAccount(std::string account_id, float account_balance, float credit_limit, float commission);

	void CashWithDrawal(float summ) override;

	std::string GetID() override;

	float GetBalance();

	void Refill(float summ) override;

	virtual std::pair<int, float> RewindTime(int days);

	void Transfer(std::string type, std::string id, float summ);

	void CanselTransaction(std::string type, std::string id, float summ);
};