#include "Account.h"

void Account::Refill(float summ) {

	if ((this->account_balance - summ) < 0)
		throw ExcessError();

	this->account_balance += summ;

}

std::string Account::GetID() {

	return this->account_id;

}

void Account::CashWithDrawal(float summ) {

	this->account_balance -= summ;

}

float Account::GetBalance() {

	return this->account_balance;

}
