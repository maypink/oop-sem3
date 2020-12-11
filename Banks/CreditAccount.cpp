#include "CreditAccount.h"

CreditAccount::CreditAccount(std::string account_id, float account_balance, float credit_limit, float commission) {

	this->account_id = account_id;

	this->account_balance = account_balance;

	this->credit_limit = credit_limit;

	this->commission = commission;

	this->curDate = 0;

}

void CreditAccount::CashWithDrawal(float summ) {

	if (summ > (account_balance + credit_limit))
		throw ExcessError();

	account_balance -= summ;

}

std::string CreditAccount::GetID() {

	return this->account_id;

}

float CreditAccount::GetBalance() {

	return this->account_balance;

}

void CreditAccount::Refill(float summ) {

	if ((this->account_balance - summ) < 0)
			throw ExcessError();

	this->account_balance += summ;

}

std::pair<int, float> CreditAccount::RewindTime(int days) {

	if (this->account_balance < 0) {

		float comissionPerDay = commission / 365;

		float loss = account_balance * comissionPerDay * days;

		if (days < 30) {

			return std::make_pair(curDate + days, account_balance);

		}

		else {

			return std::make_pair(curDate + days, account_balance - loss);

		}

	}
	else {

		return std::make_pair(days, account_balance);

	}

}

void CreditAccount::Transfer(std::string type, std::string id, float summ) {

	this->recentOperations.push_back(std::make_pair(type, std::make_pair(id, summ)));

}

void CreditAccount::CanselTransaction(std::string type, std::string id, float summ) {

	for (int i = 0; i < recentOperations.size(); ++i) {
		if (recentOperations[i].first == type && recentOperations[i].second.first == id && recentOperations[i].second.second == summ) {
			if (type == "drawal")
				this->account_balance += summ;
			else if (type == "refill")
				this->account_balance -= summ;
			recentOperations[i].first == "-1";
		}
	}
}