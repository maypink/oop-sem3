#include "Deposit.h"

Deposit::Deposit(std::string account_id, float account_balance, float percent, int account_term) {

	this->account_id = account_id;

	this->account_balance = account_balance;

	this->percent = percent;

	this->account_term = account_term;

	this->curDate = 0;

	this->bufPercent = 0;

}

std::string Deposit::GetID() {

	return this->account_id;

}

float Deposit::GetBalance() {

	return this->account_balance;

}

void Deposit::SetAccountTerm(int accountTerm) {

	this->account_term = accountTerm;

}

void Deposit::CashWithDrawal(float summ) {

	if (this->account_term > this->curDate)
		this->account_balance -= summ;
	else
		std::cout << "You cannot withdraw money from this account yet.\n";

}

void Deposit::Refill(float summ) {

	if ((this->account_balance - summ) < 0)
			throw ExcessError();

	this->account_balance += summ;

}


void Deposit::ChargingOfInterests(int days) {

	if ((days + curDate) < account_term) {

		float percentPerDay = percent / 365;

		curDate += days;

		if (days < 30)

			bufPercent += percentPerDay * days;

		else {

			this->account_balance = this->account_balance * percentPerDay * days;

		}

	}

}

std::pair<int, float> Deposit::RewindTime(int days) {

	if (days > (account_term - curDate))

		std::cout << "The balance of the deposit will be calculated at the time of the end of the deposit.\n";

	float percentPerDay = percent / 365;

	float income = this->account_balance * percentPerDay * days;

	if (days < 30)

		return std::make_pair(curDate + days, account_balance);


	else {

		return std::make_pair(curDate + days, account_balance + income);

	}

}

void Deposit::Transfer(std::string type, std::string id, float summ) {

	this->recentOperations.push_back(std::make_pair(type, std::make_pair(id, summ)));

}

void Deposit::CanselTransaction(std::string type, std::string id, float summ) {

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