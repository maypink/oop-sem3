#include "DebitAccount.h"

void DebitAccount::CashWithDrawal(float summ) {

	if ((this->account_balance-summ)>=0)
		this->account_balance -= summ;

	this->recentOperations.push_back(std::make_pair("drawal", std::make_pair("-1", summ)));

}

DebitAccount::DebitAccount(std::string account_id, float account_balance, float percent) {

	this->account_id = account_id;

	this->account_balance = account_balance;

	curDate = 0;

	bufPercent = 0;

}

std::string DebitAccount::GetID() {

	return this->account_id;

}

float DebitAccount::GetBalance() {

	return this->account_balance;

}

void DebitAccount::ChargingOfInterests(int days) { //пересчет баланса через N дней и присвоение нового значения 

	float percentPerDay = percent / 365;

	curDate += days;

	if (days < 30)

		bufPercent += percentPerDay * days;

	else {

		this->account_balance = this->account_balance * percentPerDay * days;

	}

}

void DebitAccount::Refill(float summ) {

	if ((this->account_balance - summ) < 0)
			throw ExcessError();

		this->account_balance += summ;

	this->recentOperations.push_back(std::make_pair("refill", std::make_pair("-1", summ)));

}

 std::pair<int, float> DebitAccount::RewindTime(int days) { //просто пересчет 

	float percentPerDay = percent / 365;

	float income = this->account_balance * percentPerDay * days;

	if (days < 30)

		return std::make_pair(curDate + days, account_balance);


	else {

		return std::make_pair(curDate + days, account_balance + income);

	}

}

void DebitAccount::Transfer(std::string type, std::string id, float summ) {

	this->recentOperations.push_back(std::make_pair(type, std::make_pair(id, summ)));

}

void DebitAccount::CanselTransaction(std::string type, std::string id, float summ) {

	for (int i = 0; i < recentOperations.size(); ++i) {
		if (recentOperations[i].first == "type" && recentOperations[i].second.first == "id" && recentOperations[i].second.second == summ) {
			if (type == "darwal")
				this->account_balance += summ;
			else if (type == "refill")
				this->account_balance -= summ;
			recentOperations[i].first == "-1";

		}
	}

}